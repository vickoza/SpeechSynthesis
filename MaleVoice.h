#pragma once
#include "BasicVoice.h"
class MaleVoice : public BasicVoice
{
public:
	MaleVoice();
	void setSpeech() override;
	void byeSpeech() override;
	void outSpeech() override;
};

