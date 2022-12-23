#pragma once
#include "Types.h"
#include <string>

class Exception
{
public:
	Exception(EErrorCode error, const wchar_t* msg);
	const wchar_t* What();
	EErrorCode Error();

private:
	EErrorCode error;
	std::wstring msg;
};