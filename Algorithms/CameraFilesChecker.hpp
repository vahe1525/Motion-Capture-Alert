#ifndef CAMERAFILESCHECKER_HPP
#define CAMERAFILESCHECKER_HPP

// Standart libraries
#include <iostream>
#include <sstream>
#include <memory>

// Project libraries
#include "../Exceptions/Exception.hpp"
#include "../Data/Constants.hpp"
#include "../CameraFiles/Webcam.hpp"
#include "../CameraFiles/Matrix.hpp"
#include "../Logs/Logger.hpp"

class CameraFilesChecker
{
public:

    //Checking Camera Files
    std::string CheckCameraFiles()
    {
        //Logging
        Logger::Log("Camera File checker start point ");

        std::cout << "Finding device for reading frame" << std::endl;

        //device variable
        std::string device = "/dev/video1";

        for (int j = 0; j < 2; ++j)
        {
            for (int i = 1; i < 30; ++i)
            {
                // Trying to read frame and export
                try
                {
                    Webcam webcam(device);
                    webcam.Frame();

                    //std::cout << "device is found" << std::endl;
                    Logger::Log("Camera device is found ");
                    return device;
                }
                catch (std::runtime_error)
                {
                    std::stringstream ss;
                    ss << "/dev/video";
                    ss << i;
                    device = ss.str();
                }
            }
        }

        //Log about Exception
        Logger::Log("Throwing Exception (Capture Device Not found) in Camera Checker ");

        //throwing Exception
        throw CameraFileNotFoundException("Capture device not found");
    }
};

#endif // CAMERAFILESCHECKER_HPP
