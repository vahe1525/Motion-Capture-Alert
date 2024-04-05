#ifndef COMPARER_HPP
#define COMPARER_HPP

//Standart Libraries
#include <iostream>
#include <memory>

//Files Includes
#include "../Data/Constants.hpp"
#include "../CameraFiles/Matrix.hpp"
#include "../CameraFiles/Pixel.hpp"
#include "DifferenceOfColors.hpp"

//Standart libraries
#include <iostream>

class ImageComparer
{
private:
    
    //Constants
    const double GridsCount = ((CAMERAWIDTH / SCALE) * (CAMERAHEIGHT / SCALE));

    //variables
    double percent = 0;
    int countOfTrueGrid = 0;
    double averageOfGridsColorsDiff = 0;

    //Difference Calculator object
    DifferenceOfColors DF;
    
public:

    double ComparePictures(const std::shared_ptr<Matrix> matrix1, const std::shared_ptr<Matrix> matrix2)
    {
	//loops for dividing matrix into grids
	for(int x = 0; x < CAMERAHEIGHT / SCALE; ++x)
	{
	    for(int y = 0; y < CAMERAWIDTH / SCALE; ++y)
	    {
		for(int i = x * SCALE; i < (x + 1) * SCALE; ++i)
		{
		    for(int j = y * SCALE; j < (y + 1) * SCALE; ++j)
		    {
			//calculating the sum of color differences of elements in grid
			averageOfGridsColorsDiff += DF.CalculatingDifference(matrix1->Data[i][j], matrix2->Data[i][j]);
		    } 
		}

		//Calculating average difference for grid
		averageOfGridsColorsDiff = averageOfGridsColorsDiff / (SCALE * SCALE);

		if(averageOfGridsColorsDiff <= THRESHOLD)
		{
		    ++countOfTrueGrid;
		}
	    }
	}

	//calculating percent of similarity of 2 pictures
	percent = (countOfTrueGrid / GridsCount) * 100;

	return percent;   
    }
};

#endif // COMPARER_HPP
