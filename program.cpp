#include "hellowindow.h"
#include "angles convertor.h"
#include "areas convertor.h"
#include "length convertor .h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    bool exitProgram = false; // Flag to exit the program

    while (!exitProgram) {
        unitconvertor::hellowindow^ mainWindow = gcnew unitconvertor::hellowindow();
        Application::Run(mainWindow);

        if (mainWindow->DialogResult == System::Windows::Forms::DialogResult::OK) {
            if (mainWindow->switchToLengthConverter) {
                unitconvertor::lengthconvertor^ lengthConverter = gcnew unitconvertor::lengthconvertor();
                Application::Run(lengthConverter);
                if (lengthConverter->DialogResult == System::Windows::Forms::DialogResult::OK && lengthConverter->Switchtohellowindow) {
                    continue;
                }
            }
            else if (mainWindow->switchToAnglesConverter) {
                unitconvertor::anglesconvertor^ anglesConverter = gcnew unitconvertor::anglesconvertor();
                Application::Run(anglesConverter);
                 if (anglesConverter->DialogResult == System::Windows::Forms::DialogResult::OK && anglesConverter->Switchtohellowindow) {

                     continue;
                  }
            }
            else if (mainWindow->switchToAreasConverter) {
                unitconvertor::areasconvertor^ areasConverter = gcnew unitconvertor::areasconvertor();
                Application::Run(areasConverter);
                 if (areasConverter->DialogResult == System::Windows::Forms::DialogResult::OK && areasConverter->Switchtohellowindow) {
                     continue;
                 }
            }
        }
        exitProgram = true; // Exit the program if none of the above conditions are met
    }
}
