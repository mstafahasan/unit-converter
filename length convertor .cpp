#include "length convertor .h"






namespace unitconvertor {

    lengthconvertor::lengthconvertor(void) {
        InitializeComponent();
    }

    lengthconvertor::~lengthconvertor() {
        if (components) {
            delete components;
        }
    }

    void lengthconvertor::InitializeComponent(void) {
        this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
        this->comboBoxCurrentUnit = (gcnew System::Windows::Forms::ComboBox());
        this->comboBoxTargetUnit = (gcnew System::Windows::Forms::ComboBox());
        this->textBoxAmount = (gcnew System::Windows::Forms::TextBox());
        this->buttonConvert = (gcnew System::Windows::Forms::Button());
        this->SuspendLayout();

        // Initialization of controls (unchanged)
        this->linkLabel1->AutoSize = true;
        this->linkLabel1->Location = System::Drawing::Point(654, 476);
        this->linkLabel1->Text = L"Return to hello window";
        this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &lengthconvertor::linkLabel1_LinkClicked);

        // ComboBox for current unit
        this->comboBoxCurrentUnit->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->comboBoxCurrentUnit->Items->AddRange(gcnew cli::array<System::Object^>(10) {
            L"Meter", L"Kilometer", L"Centimeter", L"Millimeter", L"Mile", L"Yard", L"Foot", L"Inch", L"Furlong", L"Acre"
        });

        // ComboBox for target unit
        this->comboBoxTargetUnit->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->comboBoxTargetUnit->Items->AddRange(gcnew cli::array<System::Object^>(10) {
            L"Meter", L"Kilometer", L"Centimeter", L"Millimeter", L"Mile", L"Yard", L"Foot", L"Inch", L"Furlong", L"Acre"
        });

        // TextBox for amount
        this->textBoxAmount->Location = System::Drawing::Point(100, 200);

        // Button for conversion
        this->buttonConvert->Text = L"Convert";
        this->buttonConvert->Click += gcnew System::EventHandler(this, &lengthconvertor::buttonConvert_Click);

        // Form settings (unchanged)
        this->ClientSize = System::Drawing::Size(938, 535);
        this->Controls->Add(this->buttonConvert);
        this->Controls->Add(this->textBoxAmount);
        this->Controls->Add(this->comboBoxTargetUnit);
        this->Controls->Add(this->comboBoxCurrentUnit);
        this->Controls->Add(this->linkLabel1);
        this->Text = L"Length Converter";
        this->ResumeLayout(false);
        this->PerformLayout();
    }

    double lengthconvertor::ConvertLength(double amount, String^ currentUnit, String^ targetUnit) {
        double meters;

        // Convert input to meters
        if (currentUnit == "Meter") {
            meters = amount;
        }
        else if (currentUnit == "Kilometer") {
            meters = amount * 1000;
        }
        else if (currentUnit == "Centimeter") {
            meters = amount / 100;
        }
        else if (currentUnit == "Millimeter") {
            meters = amount / 1000;
        }
        else if (currentUnit == "Mile") {
            meters = amount * 1609.34;
        }
        else if (currentUnit == "Yard") {
            meters = amount * 0.9144;
        }
        else if (currentUnit == "Foot") {
            meters = amount * 0.3048;
        }
        else if (currentUnit == "Inch") {
            meters = amount * 0.0254;
        }
        else if (currentUnit == "Furlong") {
            meters = amount * 201.168;
        }
        else if (currentUnit == "Acre") {
            meters = amount * 4046.86; // Convert Acre to meters
        }
        else {
            meters = 0; // Default case if unit is not recognized
        }

        // Convert from meters to target unit
        if (targetUnit == "Meter") {
            return meters;
        }
        else if (targetUnit == "Kilometer") {
            return meters / 1000;
        }
        else if (targetUnit == "Centimeter") {
            return meters * 100;
        }
        else if (targetUnit == "Millimeter") {
            return meters * 1000;
        }
        else if (targetUnit == "Mile") {
            return meters / 1609.34;
        }
        else if (targetUnit == "Yard") {
            return meters / 0.9144;
        }
        else if (targetUnit == "Foot") {
            return meters / 0.3048;
        }
        else if (targetUnit == "Inch") {
            return meters / 0.0254;
        }
        else if (targetUnit == "Furlong") {
            return meters / 201.168;
        }
        else if (targetUnit == "Acre") {
            return meters / 4046.86; // Convert back to Acre
        }

        return 0; // Default case if unit is not recognized
    }

    void lengthconvertor::linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
        Switchtohellowindow = true;
        this->DialogResult = System::Windows::Forms::DialogResult::OK;
        this->Close();
    }

    void lengthconvertor::buttonConvert_Click(System::Object^ sender, System::EventArgs^ e) {
        double amount = 0;
        if (Double::TryParse(textBoxAmount->Text, amount)) {
            String^ currentUnit = comboBoxCurrentUnit->SelectedItem->ToString();
            String^ targetUnit = comboBoxTargetUnit->SelectedItem->ToString();
            double result = ConvertLength(amount, currentUnit, targetUnit);
            MessageBox::Show("Result: " + result.ToString("F3") + " " + targetUnit); // Show result with 3 decimal points
        }
        else {
            MessageBox::Show("Please enter a valid number.");
        }
    }
}

