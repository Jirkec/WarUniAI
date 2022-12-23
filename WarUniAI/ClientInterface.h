#pragma once

#include "Types.h"
#include <windows.h>

class ClientInterface
{
public:
	ClientInterface();
	HWND GetWindow();

	void Click(SPoint point);

	void SetServer(EServer server);
	EServer GetServer();

	void SetLanguage(ELang lang);
	ELang GetLanguage();

	bool IsLoggedIn();
	EErrorCode Login(std::string name, std::string password);
	void LoginSaved(int numberInList);


private:
	HWND windowHandler;

	EErrorCode Initialize();
	EErrorCode WriteText(std::string);
};