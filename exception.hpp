#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <error.h>

#include <string>

class Exception
{
public:
    Exception(int& err_code,const char* err_str);
    virtual ~Exception();

    virtual std::string toString();

    int& getErrorCode();
    std::string& getMessage();
private:
    int err_code_;
    std::string message_;
};

class MmapError:public Exception
{
public:
    MmapError(const std::string& func_name,int& err_code,const char* err_str);
    virtual ~MmapError();

    virtual std::string toString();
private:
    std::string func_name_;
};

#endif
