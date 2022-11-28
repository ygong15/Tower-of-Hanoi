// ITP 365 Fall 2022
// HW04 – Towers of Hanoi
// Name: Yuchen Gong
// Email: yuchengo@usc.edu
// Platform: Mac

#include "disk.h"

//below is a better way to randomly generate color using rgb value. Convert the RGB value to hex by creating a stringstream and uses std::hex to build the stream
std::string generateRandomColor()
{
    int randR = rand();
    int randB = rand();
    int randG = rand();
    //randomly assign three random numbers between 0-255 to R, G, and B
    randR %= 255;
    randG %= 255;
    randB %= 255;
    //create a stringstream for conversion
    std::ostringstream colorCode;
    colorCode << "#" << std::hex << randR << randG << randB;
    //we need to convert the stringstream into str by calling str()
    return colorCode.str();
}

//constructors
Disk::Disk()
{
    mX = 0;
    mY = 0;
    mW = 0;
    mH = 0;
    mColor = generateRandomColor();
}

Disk::Disk(int x, int y, int width, int height)
{
    mX = x;
    mY = y;
    mW = width;
    mH = height;
    mColor = generateRandomColor();
}

//draw function for Disk
void Disk::draw(GWindow &gw)
{
    gw.setColor(mColor);
    gw.fillRect((mX-mW/2), (mY-mH), mW, mH);
}

//two setters for disk
void Disk::setX(int x)
{
    mX = x;
}

void Disk::setY(int y)
{
    mY = y;
}

//getter for height
int Disk::getHeight()
{
    return mH;
}

//getter function for disk's x coordinate
int Disk::getX()
{
    return mX;
}

//getter functino for disk's y coordindate
int Disk::getY()
{
    return mY;
}

