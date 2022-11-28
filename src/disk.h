// ITP 365 Fall 2022
// HW04 – Towers of Hanoi
// Name: Yuchen Gong
// Email: yuchengo@usc.edu
// Platform: Mac

#pragma once

#include <iostream>
#include "gwindow.h"
#include <string>
#include <sstream>
#include "random"
#include "gwindow.h"
#include <iostream>

// Name:
//       generateRandomColor
// Input:
//        None
// Output:
//        a string
// Side effects:
//        none
// Summary:
//        returns a string of a color code in hex form
std::string generateRandomColor();

class Disk
{
public:
    // Name:
    //        Disk default constructor
    // Input:
    //        None
    // Output:
    //        None
    // Side effects:
    //        set all parameters in disk to 0
    // Summary:
    //        Creates a Disk object
	Disk();
    
    // Name:
    //        Disk parameterized constructor
    // Input:
    //
    // Output:
    //        None
    // Side effects:
    //        Sets the money member variables to 0
    // Summary:
    //        Creates a Money object
	Disk(int x, int y, int width, int height);

    // Name:
    //        draw
    // Input:
    //        a Gwindow object
    // Output:
    //        none
    // Side effects:
    //        opening a window and draw a rectangle
    // Summary:
    //        draw a rectangle with stored parameters on screen
	void draw(GWindow& gw);

    // Name:
    //       setX
    // Input:
    //        an int
    // Output:
    //        None
    // Side effects:
    //        Sets the x coordinate of the Disk to the new passed in value
    // Summary:
    //        Update the x coordinate of a disk
	void setX(int x);
    
    // Name:
    //        setY
    // Input:
    //        an int
    // Output:
    //        None
    // Side effects:
    //        Sets the y coordinate of the Disk to the new passed in value
    // Summary:
    //        Update the y coordinate of a disk
	void setY(int y);
    
    // Name:
    //        getHeight
    // Input:
    //        none
    // Output:
    //        an int
    // Side effects:
    //        return the disk's mH value
    // Summary:
    //        return the height of a disk
	int getHeight();
    
    // Name:
    //        getX
    // Input:
    //        none
    // Output:
    //        an int
    // Side effects:
    //        return the disk's mX value
    // Summary:
    //        return the x coordinate of a disk
    int getX();
    
    // Name:
    //        getY
    // Input:
    //        none
    // Output:
    //        an int
    // Side effects:
    //        return the disk's mYvalue
    // Summary:
    //        return the y coordinate of a disk
    int getY();
    
private:
    //Rather than storing a disk's coordinate at the upper left coner
    //we store the disk's bottom center coordinate in mX and mY
	int mX;
	int mY;
    //the width of a disk
	int mW;
    //the height of a disk
	int mH;
    //the coloer of a disk
	std::string mColor;

};

