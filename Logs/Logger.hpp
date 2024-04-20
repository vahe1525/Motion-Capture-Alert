#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdexcept>

class Logger
{
private:
    const static std::string path;

public:
	
    static void Log(const std::string message) 
    {
        //taking logging time
        std::time_t time = std::time(nullptr);
        std::string timeData = std::ctime(&time);

        //creating log message 
        std::stringstream logMessage;
        logMessage << message;
        logMessage << ":: log time -> :";
        logMessage << timeData;

        //opening file 
        std::ofstream logFile(path, std::ios::app);

        if(logFile.is_open())
        {
            logFile << logMessage.str() << std::endl;
        }
        else
        {
            throw std::runtime_error("cannot open log file");
        }
        
        logFile.close();
    }

};

const std::string Logger::path = "/home/vahe1525/Documents/Vahe_Karmirshalyan/PROJECTS/SecuritySystem/Logs/Logs.txt";

#endif //LOGGER_HPP
