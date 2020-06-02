#include "exception.hpp"

Exception::Exception(int& err_code,const char* err_str)
    :err_code_(err_code),message_(err_str)
{
}

Exception::~Exception()
{}

std::string
Exception::toString()
{
    return "Exception (" + std::to_string(getErrorCode()) + ") " + getMessage();
}

int&
Exception::getErrorCode()
{
    return err_code_;
}

std::string&
Exception::getMessage()
{
    return message_;
}

MmapError::MmapError(const std::string& func_name,int& err_code,const char* err_str)
    :Exception(err_code,err_str),func_name_(func_name)
{
}

MmapError::~MmapError()
{
}

std::string
MmapError::toString()
{
    return func_name_ + " (" + std::to_string(getErrorCode()) + ") " + getMessage();
}

