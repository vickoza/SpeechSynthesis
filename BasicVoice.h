#pragma once
#include <sapi.h>
#include <string>

class BasicVoice
{
protected:
	int choice;
	ISpVoice* pVoice;
	HRESULT hr;
	std::wstring input;
	BasicVoice();
public:
	virtual ~BasicVoice();
	virtual void setSpeech() = 0;
	virtual void byeSpeech() = 0;
	virtual void outSpeech() = 0;
};

