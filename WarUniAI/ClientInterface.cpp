#include "ClientInterface.h"

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


void ClientInterface::Click(SPoint point)
{
    RECT rect = { 0 };
    //GetWindowRect(windowHandler, &rect);
    //Sleep(300);
    SetCursorPos(point.x, point.y + Y_OFFSET);
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
