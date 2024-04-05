#ifndef CAPTURER_HPP
#define CAPTURER_HPP

//Standart Libraries
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

//File Includes 
#include "../Data/Constants.hpp"
#include "../CameraFiles/Matrix.hpp"
#include "../CameraFiles/BMPExporter.hpp"
#include "../CameraFiles/Webcam.hpp"
#include "Comparer.hpp"
#include "CameraFilesChecker.hpp"

class Capturer
{
private:
	// variable for counting pictures
	static int pictureNumber;

	//variable for motion fixing count;
	int fixedMotion = 0;

	// Light Adjusting
	void LightAdjusting(Webcam &adjuster)
	{
		std::cout << "Light adjusting starting" << std::endl;
		for (int i = 0; i < 40; ++i)
		{
			adjuster.Frame();
		}
		std::cout << "Light adjusting finished" << std::endl;
	}

	// Updates the name of exporting picture
	std::string UpdatingNameOfPicture()
	{
		std::stringstream ss;
		ss << "Output/PIcture-";
		ss << ++pictureNumber;

		return ss.str();
	}

	bool Capture(std::string device)
	{
	    // Webcam object
	    Webcam webcam(device);

	    // Matrixes
	    std::shared_ptr<Matrix> current = std::make_shared<Matrix>();
	    std::shared_ptr<Matrix> previous = std::make_shared<Matrix>();

	    // Light adjusting
	    LightAdjusting(webcam);

	    std::cout << "Video Surveillance is started " << std::endl;
	    while (true)
	    {
		if(fixedMotion >= 8)
		{
		    return false; 
		}

		// Reading frame
		current = webcam.Frame();

		// Image Comparer object
		ImageComparer comparer;

		// checking matrixes content
		if (!current->IsEmpty() && !previous->IsEmpty())
		{
		    // Comparing pictures/t
		    double percent = comparer.ComparePictures(current, previous);

		    // Exporter objects
		    BMPExporter exporter;

		    // Checking Motion in frame
		    if (percent < PERCENTTHRESHOLD)
		    {
			std::string name = UpdatingNameOfPicture();
			//std::cout << "There is a motion in the frame!!! Look the pictures! " << std::endl;
			
			// Exporting Pictures
			exporter.Export(current, name);
			name = UpdatingNameOfPicture();
			exporter.Export(previous, name);
			++fixedMotion;
		    }
		}
		// Updating previous matrix
		previous = current;
	    }

	    return true;
	}

public:
	bool Start()
	{
	    // Finding device for reading Frame
	    CameraFilesChecker checker;
	    std::string device = checker.CheckCameraFiles();

	    try
	    {
		bool res = Capture(device);
		return res;
	    }
	    catch (const std::runtime_error &e)
	    {
		std::cout << "From Capturer caught error" << e.what() <<  std::endl;
		return true;
	    }
	}
};

int Capturer::pictureNumber = 0;

#endif //CAPTURER_HPP
