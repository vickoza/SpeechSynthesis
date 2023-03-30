#include <exception>
#include <iostream>
#include "FemaleVoice.h"

FemaleVoice::FemaleVoice() : BasicVoice()
{
}

void FemaleVoice::setSpeech()
{
	if (SUCCEEDED(hr))
	{
		std::cout << "Enter text:\n";
		std::cin.ignore(1, '\n');
		getline(std::wcin, input);
	}
	std::cout << "At What Speed you want to Play your Voice\n1 for Normal \n2 for -2x\n3 for 2x";
	std::cin >> choice;
	if (choice == 2)
		hr = pVoice->Speak((L"<rate absspeed='-2'><voice required='Gender = Female;'>" + input).c_str(), 0, nullptr);
	else if (choice == 3)
		hr = pVoice->Speak((L"<rate absspeed='2'><voice required='Gender = Female;'>" + input).c_str(), 0, nullptr);
	else
		hr = pVoice->Speak((L"<voice required='Gender = Female;'>" + input).c_str(), 0, nullptr);
}

void FemaleVoice::byeSpeech()
{
	if (SUCCEEDED(hr))
	{
		hr = pVoice->Speak(L"<voice required='Gender = Female'> < rate absspeed = '-5' > Bhut Shukria Sir", 0, nullptr);
	}
}

void FemaleVoice::outSpeech()
{
	pVoice->Release();
	pVoice = nullptr;
	::CoUninitialize();
}
