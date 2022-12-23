#include "ClientInterface.h"

int main()
{
    try
    {
        ClientInterface clientInterface;

        //Sleep(1000);
        clientInterface.Click(CLIENT_COORDINATIONS.at("lang_button"));
    }
    catch (EErrorCode err)
    {
        printf(GetNameOfError(err).c_str());
    }

}