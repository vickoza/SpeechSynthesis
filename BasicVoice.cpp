#include <exception>
#include "BasicVoice.h"

BasicVoice::BasicVoice() : pVoice{ nullptr }, input{L""}
{
	HRESULT a = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);//HRESULT CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
	if (FAILED(a))
	{
		throw std::exception("ERROR 404 FAILED INITIALIZING COM");
	}
	hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);
}

BasicVoice::~BasicVoice()
{
	::CoUninitialize();
	delete pVoice;
}
