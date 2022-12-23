#include "Exception.h"

Exception::Exception(EErrorCode error, const wchar_t* msg) : error(error), msg(msg)
{
}

const wchar_t* Exception::What()
{
    return msg.c_str();
}

EErrorCode Exception::Error()
{
    return error;
}
