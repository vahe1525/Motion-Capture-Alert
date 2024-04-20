#ifndef MANAGER_HPP
#define MANAGER_HPP

//Standart Libraries
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <thread>

//File Includes 
#include "Algorithms/Capturer.hpp"
#include "Logs/Logger.hpp"

class Manager
{
private:

	void SendEmail()
	{
		Logger::Log("Sending Email function in Manager ");
		system("dotnet run");
	}

	// Deleting Files in Output
	void ClearingOutput()
	{
		Logger::Log("Output Cleaning Procces in Manager ");

		std::cout << "Clearing Output..." << std::endl;

		system("rm Output/* -r");
		system("ls Output/");

		std::cout << "Clearing finished" << std::endl;
		std::cout << "Output is clear" << std::endl;
	}

	//Taking User Data 
	void TakeUserData()
	{
		Logger::Log("Taking User Info ");

		//Saving File Path
		std::string filePath = "Data/Data.txt";

		//User Data variables
		std::string userEmail = "";
		std::string username = "";

		std::cout << "PLEASE REGISTER YOUR DATA FOR USING OUR PROGRAM " << std::endl;

		//taking username for our program
		std::cout << "Your username --->> ";
		std::cin >> username; 

		// taking user Email
		std::cout << "Your Email --->> ";
		std::cin >> userEmail;

		// Saving User Data
		//  Open a file for writing
		std::ofstream File(filePath);

		// Check if the file is open
		if (File.is_open())
		{
			// Write data to the file
			File << userEmail << std::endl;

			// Close the file
			File.close();
		}
	}

public:
	void Start()
	{
		Logger::Log("Manager Start Function has started");

	    //Taking user Data
	    TakeUserData();

	    // Deleting Files
	    ClearingOutput();

	    while(true)
	    {
		//Capturing
		Capturer capturer;
		bool res = capturer.Start();

		if(res == false)
		{
		    //Sending Email with thread
		    std::thread senderThread(&Manager::SendEmail, this);
		    senderThread.detach();
		}
	    }
	}
};

#endif // MANAGER_HPP
