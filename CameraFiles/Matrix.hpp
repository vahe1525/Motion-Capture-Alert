           
#ifndef MATRIX
#define MATRIX

// Standard libraries
#include <iostream>

// Project librarie
#include "../Data/Constants.hpp"
#include "Pixel.hpp"

class Matrix
{
private:

	//Varibale for checking matrix
	bool Empty_status = true;

public:
	
	// Dimentions
	int Width = 0;
	int Height = 0;

	// Data
	Pixel Data[CAMERAHEIGHT][CAMERAWIDTH];

	Matrix()
	{
		Width = CAMERAWIDTH;
		Height = CAMERAHEIGHT;
	}

	
	Matrix (const Matrix& matrix)
	{
	    std::cout << "copy" << std::endl;

	    this->Height = CAMERAHEIGHT;
	    this->Width = CAMERAWIDTH;

	    for (int i = 0; i < CAMERAHEIGHT; ++i)
	    {
		for (int j = 0; j < CAMERAWIDTH; ++j)
		{
		    this->Data[i][j] = matrix.Data[i][j];
		}
	    }

	}

	Matrix operator = (const Matrix& matrix)
	{
	    this->Empty_status = false;

	    std::cout << "matrix operator =" << std::endl;
	    Matrix copyMatrix;

	    copyMatrix.Height = CAMERAHEIGHT;
	    copyMatrix.Width = CAMERAWIDTH;

	    for (int i = 0; i < CAMERAHEIGHT; ++i)
	    {
		for (int j = 0; j < CAMERAWIDTH; ++j)
		{
		    copyMatrix.Data[i][j] = matrix.Data[i][j];
		}
	    }

	    return copyMatrix;
	}

	//Checking is matrix empty or not
	bool IsEmpty()
	{
	    for (int i = 0; i < CAMERAHEIGHT; ++i)
	    {
		for (int j = 0; j < CAMERAWIDTH; ++j)
		{
		    //checking the content
		    if(this->Data[i][j].R == 255 || this->Data[i][j].G == 255 || this->Data[i][j].B == 255)
		    {
		    }
		    else
		    {
			return false;
		    }
		}
	    }

	    return true;
	}
	

	/*
	void operator = (const Matrix& matrix)
	{
	    std::cout << "AAAAAAAAAAAAAAAA" << std::endl;

	    for (int i = 0; i < CAMERAHEIGHT; ++i)
	    {
		for (int j = 0; j < CAMERAWIDTH; ++j)
		{
		    this->Data[i][j] = matrix.Data[i][j];
		}
	    }
	}
	*/

};
#endif // MATRIX
