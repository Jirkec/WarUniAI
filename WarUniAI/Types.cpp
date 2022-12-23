#include "Types.h"

std::string GetNameOfError(EErrorCode error)
{
	std::string nameOfError;
	switch (error)
	{
	case EErrorCode::OK:
		nameOfError = "OK"; break;
	case EErrorCode::CLIENT_WINDOW_ERROR:
		nameOfError = "CLIENT_WINDOW_ERROR"; break;
	default:
		nameOfError = "Invalid error";
	}

	return nameOfError;
}