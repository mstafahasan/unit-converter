#pragma once

namespace unitconvertor {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for anglesconvertor
    /// </summary>
    public ref class anglesconvertor : public System::Windows::Forms::Form
    {
    public:
        anglesconvertor(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~anglesconvertor()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::LinkLabel^ switchToMain;
    protected:

    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->switchToMain = (gcnew System::Windows::Forms::LinkLabel());
            this->SuspendLayout();
            // 
            // switchToMain
            // 
            this->switchToMain->AutoSize = true;
            this->switchToMain->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->switchToMain->LinkColor = System::Drawing::Color::Black;
            this->switchToMain->Location = System::Drawing::Point(507, 395);
            this->switchToMain->Name = L"switchToMain";
            this->switchToMain->Size = System::Drawing::Size(245, 28);
            this->switchToMain->TabIndex = 0;
            this->switchToMain->TabStop = true;
            this->switchToMain->Text = L"Return to hello window";
            this->switchToMain->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &anglesconvertor::switchToMain_LinkClicked);
            // 
            // anglesconvertor
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(763, 459);
            this->Controls->Add(this->switchToMain);
            this->Name = L"anglesconvertor";
            this->Text = L"anglesconvertor";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    public:	bool Switchtohellowindow = false;
    private: System::Void switchToMain_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
        Switchtohellowindow = true;
        this->DialogResult = System::Windows::Forms::DialogResult::OK;
        this->Close();
    }
    };
}
