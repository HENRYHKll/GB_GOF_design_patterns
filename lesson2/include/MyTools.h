#pragma once
#include <cstring>
#include <fstream>
#include <string>

class IFileLogger
{
public:
    virtual ~IFileLogger()                                           = default;
    virtual void        OpenLogFile(const std::string& FN)           = 0;
    virtual void        CloseLogFile()                               = 0;
    virtual void        WriteToLog(const std::string& str)           = 0;
    virtual void        WriteToLog(const std::string& str, int n)    = 0;
    virtual void        WriteToLog(const std::string& str, double d) = 0;
    virtual std::string GetCurDateTime()                             = 0;
};

class FileLoggerSingletone : public IFileLogger
{
public:
    static FileLoggerSingletone& getInstance()
    {
        static FileLoggerSingletone theInstance;
        return theInstance;
    }

    void                OpenLogFile(const std::string& FN) override;
    void                CloseLogFile() override;
    void                WriteToLog(const std::string& str) override;
    void                WriteToLog(const std::string& str, int n) override;
    void                WriteToLog(const std::string& str, double d) override;
    virtual std::string GetCurDateTime() override;

private:
    std::ofstream                logOut;

    FileLoggerSingletone()                                 = default;
    ~FileLoggerSingletone()                                = default;
    FileLoggerSingletone(const FileLoggerSingletone& root) = delete;
    FileLoggerSingletone& operator=(const FileLoggerSingletone&) = delete;
    FileLoggerSingletone(FileLoggerSingletone&& root)            = delete;
    FileLoggerSingletone& operator=(FileLoggerSingletone&&) = delete;
};
