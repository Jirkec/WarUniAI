#include "ClientInterface.h"

int main()
{
    ClientInterface clientInterface;
    POINT p;

    while (true)
    {
        GetCursorPos(&p);
        if (ScreenToClient(clientInterface.GetWindow(), &p))
        {
            printf("X:%d Y:%d\n", p.x, p.y);
        }

        Sleep(700);
    }
}