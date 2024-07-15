#pragma once

#include "length_converter.h"
#include "angles_converter.h"
#include "areas_converter.h"

namespace unitconvertor {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class hellowindow : public System::Windows::Forms::Form
    {
    public:
        bool switchToLengthConverter = false;
        bool switchToAnglesConverter = false;
        bool switchToAreasConverter = false;

        hellowindow(void)
        {
            InitializeComponent();
        }

    protected:
        ~hellowindow()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::LinkLabel^ linkLabel1;
    private: System::Windows::Forms::LinkLabel^ linkLabel2;
    private: System::Windows::Forms::LinkLabel^ linkLabel3;
    private: System::Windows::Forms::Label^ label2;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(hellowindow::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel3 = (gcnew System::Windows::Forms::LinkLabel());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(224, 201);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(264, 36);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Select Your Goal";
            // 
            // linkLabel1
            // 
            this->linkLabel1->AutoSize = true;
            this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->linkLabel1->LinkColor = System::Drawing::Color::Black;
            this->linkLabel1->Location = System::Drawing::Point(76, 271);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(82, 28);
            this->linkLabel1->TabIndex = 1;
            this->linkLabel1->TabStop = true;
            this->linkLabel1->Text = L"Length";
            this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &hellowindow::linkLabel1_LinkClicked);
            // 
            // linkLabel2
            // 
            this->linkLabel2->AutoSize = true;
            this->linkLabel2->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->linkLabel2->LinkColor = System::Drawing::Color::Black;
            this->linkLabel2->Location = System::Drawing::Point(529, 271);
            this->linkLabel2->Name = L"linkLabel2";
            this->linkLabel2->Size = System::Drawing::Size(79, 28);
            this->linkLabel2->TabIndex = 2;
            this->linkLabel2->TabStop = true;
            this->linkLabel2->Text = L"Angles";
            this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &hellowindow::linkLabel2_LinkClicked);
            // 
            // linkLabel3
            // 
            this->linkLabel3->AutoSize = true;
            this->linkLabel3->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->linkLabel3->LinkColor = System::Drawing::Color::Black;
            this->linkLabel3->Location = System::Drawing::Point(318, 271);
            this->linkLabel3->Name = L"linkLabel3";
            this->linkLabel3->Size = System::Drawing::Size(68, 28);
            this->linkLabel3->TabIndex = 3;
            this->linkLabel3->TabStop = true;
            this->linkLabel3->Text = L"Areas";
            this->linkLabel3->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &hellowindow::linkLabel3_LinkClicked);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(31, 28);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(457, 24);
            this->label2->TabIndex = 4;
            this->label2->Text = L"Hello our user, here we convert any unit you want";
            // 
            // hellowindow
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(717, 404);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->linkLabel3);
            this->Controls->Add(this->linkLabel2);
            this->Controls->Add(this->linkLabel1);
            this->Controls->Add(this->label1);
            this->Name = L"hellowindow";
            this->Text = L"hellowindow";
            this->Load += gcnew System::EventHandler(this, &hellowindow::hellowindow_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void hellowindow_Load(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
        switchToLengthConverter = true;
        this->DialogResult = System::Windows::Forms::DialogResult::OK;
        this->Close();
    }
private: System::Void linkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
    switchToAnglesConverter = true;
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    this->Close();
}

    private: System::Void linkLabel3_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
        switchToAreasConverter = true;
        this->DialogResult = System::Windows::Forms::DialogResult::OK;
        this->Close();
    }
    };
}
