#include "MyTools.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <time.h>



void FileLoggerSingletone::OpenLogFile(const std::string& FN)
{
    logOut.open(FN, std::ios_base::out);
}

void FileLoggerSingletone::CloseLogFile()
{
    if (logOut.is_open())
    {
        logOut.close();
    }
}

std::string FileLoggerSingletone::GetCurDateTime()
{
    auto   cur  = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char*  buf  = ctime(&time);
    return std::string(buf);
}

void FileLoggerSingletone::WriteToLog(const std::string& str)
{
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << std::endl;
    }
}

void FileLoggerSingletone::WriteToLog(const std::string& str, int n)
{
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << n << std::endl;
    }
}

void FileLoggerSingletone::WriteToLog(const std::string& str, double d)
{
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << d << std::endl;
    }
}
