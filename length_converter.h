#pragma once

namespace unitconvertor {

    using namespace System;

    public ref class lengthconvertor : public System::Windows::Forms::Form
    {
    public:
        lengthconvertor(void);
    protected:
        ~lengthconvertor();

    private:
        System::Windows::Forms::LinkLabel^ linkLabel1;
        System::Windows::Forms::ComboBox^ comboBoxCurrentUnit;
        System::Windows::Forms::ComboBox^ comboBoxTargetUnit;
        System::Windows::Forms::TextBox^ textBoxAmount;
        System::Windows::Forms::Button^ buttonConvert;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void);
        double ConvertLength(double amount, String^ currentUnit, String^ targetUnit);

    public:
        bool Switchtohellowindow = false;

    private:
        System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
        System::Void lengthconvertor_Load(System::Object^ sender, System::EventArgs^ e);
        System::Void buttonConvert_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
