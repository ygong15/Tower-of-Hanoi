// ITP 365 Fall 2022
// HW04 – Towers of Hanoi
// Name: Yuchen Gong
// Email: yuchengo@usc.edu
// Platform: Mac

#pragma once

#include <string>

#include <vector>
#include "gwindow.h"

#include "disk.h"

class Peg
{
public:
    // Name:
    //        peg default constructor
    // Input:
    //        None
    // Output:
    //        None
    // Side effects:
    //        set all parameters in peg to 0
    // Summary:
    //        Creates a peg object
	Peg();
    
    // Name:
    //        peg parameterized constructors
    // Input:
    //        None
    // Output:
    //        None
    // Side effects:
    //        set all parameters according to inputs
    // Summary:
    //        Creates a peg object
	Peg(int x, int y , int width, int height);

    // Name:
    //        draw
    // Input:
    //        a Gwindow object
    // Output:
    //        none
    // Side effects:
    //        opening a window and draw a peg with ll disks that are on the peg
    // Summary:
    //        draw a peg will all disks belonged to the peg
	void draw(GWindow& gw);
    
    // Name:
    //        addDisk
    // Input:
    //        a disk object
    // Output:
    //        none
    // Side effects:
    //       pushing a disk object to the last index of the diskVector and updated its x,y coordinate
    // Summary:
    //       adding a disk into the diskVeector and updates its coordinate
	void addDisk(Disk inDisk);
    
    // Name:
    //        removeDisk
    // Input:
    //        noen
    // Output:
    //        a Disk object
    // Side effects:
    //        remove the last disk in the vector and returns it
    // Summary:
    //        return the last disk in a peg vector and pops it off the vector
	Disk removeDisk();
    
private:
	int mX;
	int mY;
	int mW;
	int mH;
	int xCenter;
	int curTop;

	std::string color;

	std::vector<Disk> diskVect;
};
