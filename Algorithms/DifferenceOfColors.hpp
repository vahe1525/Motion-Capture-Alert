#ifndef DIFFERENCEOFCOLORS_HPP
#define DIFFERENCEOFCOLORS_HPP

//Standart Libraries
#include <cmath>

//Files
#include "../CameraFiles/Pixel.hpp"

class DifferenceOfColors
{
public:
    // calculating difference between two colors
    double CalculatingDifference(Pixel a, Pixel b)
    {
        double diff = sqrt(pow((a.R - b.R), 2) + pow((a.G - b.G), 2) + pow((a.B - b.B), 2));
        return diff;
    }
};

#endif // DIFFERENCEOFCOLORS_HPP
