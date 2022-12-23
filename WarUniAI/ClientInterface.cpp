#include "ClientInterface.h"
#include <vector>

ClientInterface::ClientInterface()
{
    windowHandler = FindWindowW(nullptr, CLIENT_WINDOW_NAME);
    if (windowHandler == NULL)
    {
        DWORD last_error = GetLastError();
        wprintf(L"ClientInterface(): Unable to find window with name %s GetLastError = 0x%08X \n", CLIENT_WINDOW_NAME, last_error);
        throw EErrorCode::CLIENT_WINDOW_ERROR;
    }

    Initialize();
}

HWND ClientInterface::GetWindow()
{
    return windowHandler;
}

EErrorCode ClientInterface::Login(std::string name, std::string password)
{
    EErrorCode result = EErrorCode::OK;

    Click(CLIENT_COORDINATIONS.at("login_name_textarea"));
    result = WriteText(name);
    if (result == EErrorCode::OK)
    {
        Click(CLIENT_COORDINATIONS.at("login_pass_textarea"));
        result = WriteText(password);
        if (result == EErrorCode::OK)
        {
            Click(CLIENT_COORDINATIONS.at("login_button"));
        }
    }

    return result;
}

void ClientInterface::LoginSaved(int numberInList)
{    
    Click({ 
            CLIENT_COORDINATIONS.at("login_saved").x, 
            CLIENT_COORDINATIONS.at("login_saved").y + (LOGIN_SAVED_INCREMENT * numberInList) 
        });
}

EErrorCode ClientInterface::Initialize()
{
    EErrorCode result = EErrorCode::OK;

    bool moveResult = MoveWindow(windowHandler, 0, 0, WINDOWS_WIDTH, WINDOW_HEIGHT, true);
    if (!moveResult)
    {
        result = EErrorCode::CLIENT_WINDOW_ERROR;
        DWORD last_error = GetLastError();
        wprintf(L"ClientInterface(): Unable to find window with name %s GetLastError = 0x%08X \n", CLIENT_WINDOW_NAME, last_error);
    }

    ShowWindow(windowHandler, SW_SHOW);
    SetForegroundWindow(windowHandler);
    SetActiveWindow(windowHandler);
    SetFocus(windowHandler);

    return result;
}

EErrorCode ClientInterface::WriteText(std::string text)
{
    EErrorCode result = EErrorCode::OK;
    std::vector<INPUT> inputs;
    for (int i = 0; i < text.length(); i++)
    {
        INPUT tmpInput = { INPUT_KEYBOARD , text.at(i), 0};
        inputs.push_back(tmpInput);
    }

    UINT uSent = SendInput(inputs.size(), &inputs[0], sizeof(INPUT));
    if (uSent != inputs.size())
    {
        DWORD last_error = GetLastError();
        printf("SendInput failed: 0x%x\n", last_error);
        result = EErrorCode::SEND_INPUT_FAILED;
    }

    return result;
}


void ClientInterface::Click(SPoint point)
{
    RECT rect = { 0 };
    //GetWindowRect(windowHandler, &rect);
    //Sleep(300);
    SetCursorPos(point.x, point.y + Y_OFFSET);
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
