#pragma once

namespace unitconvertor {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class lengthconvertor : public System::Windows::Forms::Form
    {
    public:
        lengthconvertor(void)
        {
            InitializeComponent();
        }

    protected:
        ~lengthconvertor()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::LinkLabel^ linkLabel1;
        System::Windows::Forms::ComboBox^ comboBoxCurrentUnit;
        System::Windows::Forms::ComboBox^ comboBoxTargetUnit;
        System::Windows::Forms::TextBox^ textBoxAmount;
        System::Windows::Forms::Button^ buttonConvert;
        System::ComponentModel::Container^ components;

    private:
        void InitializeComponent(void)
        {
            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            this->comboBoxCurrentUnit = (gcnew System::Windows::Forms::ComboBox());
            this->comboBoxTargetUnit = (gcnew System::Windows::Forms::ComboBox());
            this->textBoxAmount = (gcnew System::Windows::Forms::TextBox());
            this->buttonConvert = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();

            // linkLabel1
            this->linkLabel1->AutoSize = true;
            this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12));
            this->linkLabel1->Location = System::Drawing::Point(80, 280); // Adjusted position
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(216, 24);
            this->linkLabel1->TabIndex = 0;
            this->linkLabel1->TabStop = true;
            this->linkLabel1->Text = L"Return to hello window";
            this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &lengthconvertor::linkLabel1_LinkClicked);

            // comboBoxCurrentUnit
            this->comboBoxCurrentUnit->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboBoxCurrentUnit->Font = (gcnew System::Drawing::Font(L"Tahoma", 10));
            this->comboBoxCurrentUnit->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
                L"Meter", L"Kilometer", L"Centimeter",
                    L"Millimeter", L"Mile", L"Yard", L"Foot", L"Inch", L"Furlong", L"Acre"
            });
            this->comboBoxCurrentUnit->Location = System::Drawing::Point(50, 50);
            this->comboBoxCurrentUnit->Name = L"comboBoxCurrentUnit";
            this->comboBoxCurrentUnit->Size = System::Drawing::Size(200, 30);
            this->comboBoxCurrentUnit->TabIndex = 1;

            // comboBoxTargetUnit
            this->comboBoxTargetUnit->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboBoxTargetUnit->Font = (gcnew System::Drawing::Font(L"Tahoma", 10));
            this->comboBoxTargetUnit->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
                L"Meter", L"Kilometer", L"Centimeter",
                    L"Millimeter", L"Mile", L"Yard", L"Foot", L"Inch", L"Furlong", L"Acre"
            });
            this->comboBoxTargetUnit->Location = System::Drawing::Point(50, 100);
            this->comboBoxTargetUnit->Name = L"comboBoxTargetUnit";
            this->comboBoxTargetUnit->Size = System::Drawing::Size(200, 30);
            this->comboBoxTargetUnit->TabIndex = 2;

            // textBoxAmount
            this->textBoxAmount->Font = (gcnew System::Drawing::Font(L"Tahoma", 10));
            this->textBoxAmount->Location = System::Drawing::Point(50, 150);
            this->textBoxAmount->Name = L"textBoxAmount";
            this->textBoxAmount->Size = System::Drawing::Size(200, 30);
            this->textBoxAmount->TabIndex = 3;

            // buttonConvert
            this->buttonConvert->Font = (gcnew System::Drawing::Font(L"Tahoma", 10));
            this->buttonConvert->Location = System::Drawing::Point(50, 200);
            this->buttonConvert->Name = L"buttonConvert";
            this->buttonConvert->Size = System::Drawing::Size(120, 30);
            this->buttonConvert->TabIndex = 4;
            this->buttonConvert->Text = L"Convert";
            this->buttonConvert->UseVisualStyleBackColor = true;
            this->buttonConvert->Click += gcnew System::EventHandler(this, &lengthconvertor::buttonConvert_Click);

            // lengthconvertor
            this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(300, 350); // Set smaller size
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle; // Optional: change as needed
            this->Controls->Add(this->buttonConvert);
            this->Controls->Add(this->textBoxAmount);
            this->Controls->Add(this->comboBoxTargetUnit);
            this->Controls->Add(this->comboBoxCurrentUnit);
            this->Controls->Add(this->linkLabel1);
            this->Name = L"lengthconvertor";
            this->Text = L"Length Converter";
            this->Load += gcnew System::EventHandler(this, &lengthconvertor::lengthconvertor_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }

    public:
        bool Switchtohellowindow = false;

    private:
        System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            Switchtohellowindow = true;
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();
        }

    private:
        System::Void lengthconvertor_Load(System::Object^ sender, System::EventArgs^ e) {
        }

    private:
        System::Void buttonConvert_Click(System::Object^ sender, System::EventArgs^ e) {
            double amount = 0;
            if (Double::TryParse(textBoxAmount->Text, amount)) {
                String^ currentUnit = comboBoxCurrentUnit->SelectedItem->ToString();
                String^ targetUnit = comboBoxTargetUnit->SelectedItem->ToString();
                double result = ConvertLength(amount, currentUnit, targetUnit);
                MessageBox::Show("Result: " + result.ToString() + " " + targetUnit);
            }
            else {
                MessageBox::Show("Please enter a valid number.");
            }
        }

    private:
        double ConvertLength(double amount, String^ currentUnit, String^ targetUnit) {
            double baseAmount = 0;

            if (currentUnit == "Meter") baseAmount = amount;
            else if (currentUnit == "Kilometer") baseAmount = amount * 1000;
            else if (currentUnit == "Centimeter") baseAmount = amount / 100;
            else if (currentUnit == "Millimeter") baseAmount = amount / 1000;
            else if (currentUnit == "Mile") baseAmount = amount * 1609.34;
            else if (currentUnit == "Yard") baseAmount = amount * 0.9144;
            else if (currentUnit == "Foot") baseAmount = amount * 0.3048;
            else if (currentUnit == "Inch") baseAmount = amount * 0.0254;
            else if (currentUnit == "Furlong") baseAmount = amount * 201.168;
            else if (currentUnit == "Acre") baseAmount = amount * 4046.86; // Adjusted conversion

            if (targetUnit == "Meter") return baseAmount;
            else if (targetUnit == "Kilometer") return baseAmount / 1000;
            else if (targetUnit == "Centimeter") return baseAmount * 100;
            else if (targetUnit == "Millimeter") return baseAmount * 1000;
            else if (targetUnit == "Mile") return baseAmount / 1609.34;
            else if (targetUnit == "Yard") return baseAmount / 0.9144;
            else if (targetUnit == "Foot") return baseAmount / 0.3048;
            else if (targetUnit == "Inch") return baseAmount / 0.0254;
            else if (targetUnit == "Furlong") return baseAmount / 201.168;
            else if (targetUnit == "Acre") return baseAmount / 4046.86; // Adjusted conversion

            return 0;
        }
    };
}
