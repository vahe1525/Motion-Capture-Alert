#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

//Standart Libraries
#include <iostream>
#include <stdexcept>

//Base Exception class
class MyException : public std::runtime_error 
{
public:
    MyException(const char* message) : std::runtime_error(message)
    {
    }
};

//Camera Excpetion (capture device not found)
class CameraFileNotFoundException : public MyException
{
public:
    CameraFileNotFoundException(const char* message) : MyException(message) 
    {
    }
};

#endif //EXCEPTION_HPP
