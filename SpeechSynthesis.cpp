// SpeechSynthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sapi.h>
#include <string>

using namespace std::string_literals;

int main()
{
    std::cout << "Hello World!\n";
    ISpVoice* pVoice = nullptr;
    HRESULT hr;
    std::wstring input;
    auto a = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    if (FAILED(a))
    {
        std::cout << "ERROR 404 FAILED INITIALIZING COM\n";
        exit(1);
    }
    //HRESULT CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
    hr = CoCreateInstance(CLSID_SpVoice, nullptr, CLSCTX_ALL, IID_ISpVoice, reinterpret_cast<void**>(&pVoice));

    if (SUCCEEDED(hr))
    {
        std::getline(std::wcin, input);
        hr = pVoice->Speak(input.c_str(), 0, nullptr);
        pVoice->Release();
        pVoice = nullptr;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
