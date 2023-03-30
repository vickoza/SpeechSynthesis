#include <exception>
#include <iostream>
#include "MaleVoice.h"

MaleVoice::MaleVoice() : BasicVoice()
{
}

void MaleVoice::setSpeech()
{
	if (SUCCEEDED(hr))
	{
		std::cout << "Enter text:\n";
		std::cin.ignore(1, '\n');
		getline(std::wcin, input);
	}
	else
	{
		throw std::exception("NOt Initalized");
	}
	system("cls");
	std::cout << "At What Speed you want to Play your Voice\n1 for Normal \n2 for -2x\n3 for 2x";
	std::cin >> choice;
	if (choice == 2)
		hr = pVoice->Speak((L"<rate absspeed='-2'>" + input).c_str(), 0, nullptr);
	else if (choice == 3)
		hr = pVoice->Speak((L"<rate absspeed='2'>" + input).c_str(), 0, nullptr);
	else
		hr = pVoice->Speak(input.c_str(), 0, nullptr);
}

void MaleVoice::byeSpeech()
{
}

void MaleVoice::outSpeech()
{
	pVoice->Release();
	pVoice = nullptr;
	::CoUninitialize();
}
