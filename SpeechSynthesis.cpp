// SpeechSynthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <memory>
#include <exception>
#include"BasicVoice.h"
#include "MaleVoice.h"
#include "FemaleVoice.h"

using namespace std::string_literals;

int main()
{
    std::cout << "Hello World!\n";
    std::unique_ptr<BasicVoice> b1{nullptr};
    try
    {
        int choice;
        do {
            std::cout << "1 to Output in Male Voice \n2 to Output in Female Voice\n";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                b1 = std::make_unique<MaleVoice>(); //  we create a new malevoice object.
                b1->setSpeech();
                b1->outSpeech();
                break;
            case 2:
                b1 = std::make_unique<FemaleVoice>();// we create a new femalevoice
                b1->setSpeech();
                b1->outSpeech();
                break;
            case 3:
                b1 = std::make_unique<FemaleVoice>();
                b1->byeSpeech();
                b1->outSpeech();
                break;
            default:
                break;
            }
        } while (choice != 3);
        system("pause");
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
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
