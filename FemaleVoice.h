#pragma once
#include "BasicVoice.h"

class FemaleVoice : public BasicVoice
{
public:
	FemaleVoice();
	void setSpeech() override;
	void byeSpeech() override;
	void outSpeech() override;
};

