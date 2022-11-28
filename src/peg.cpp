// ITP 365 Fall 2022
// HW04 – Towers of Hanoi
// Name: Yuchen Gong
// Email: yuchengo@usc.edu
// Platform: Mac

#include "peg.h"

//all pegs will be black
const std::string COLOR = "BLACK";

//constructors
Peg::Peg()
{
    mX = 0;
    mY = 0;
    mW = 0;
    mH = 0;
    color = COLOR;
    //we make sure the space allocated for diskVector will be empty
    diskVect.clear();
}

//parameterized constructors
Peg::Peg(int x, int y, int width, int height)
{
    mX = x;
    mY = y;
    mW = width;
    mH = height;
    color = COLOR;
    //we make sure the space allocated for diskVector will be empty
    diskVect.clear();
}

//draw function for the peg
void Peg::draw(GWindow &gw)
{
    gw.setColor(color);
    gw.fillRect((mX-mW*0.5),(mY-mH), mW, mH);
    
    for(Disk d : diskVect)
    {
        d.draw(gw);
    }
    
}

//addDisk function for the peg
void Peg::addDisk(Disk inDisk)
{
    //set the disk's x and y coordinate the same as the peg's
    inDisk.setX(mX);
    inDisk.setY(mY);
    //if the disk is the first one on the peg no modification of its y coordinate  will be needed. Directly add into the vector
    if(diskVect.empty())
    {
        diskVect.push_back(inDisk);
    }
    //if the disk is not the first one, we need to add up all previous disks' heights and subtract the value from the incoming disk's y coordinate
    else
    {
        int currHeight = 0;
        for(Disk d : diskVect)
        {
            currHeight += d.getHeight();
        }
        //the current disk's y is set to the bottom of the screen. Thus, we subtract all previous disks' hieights from it to get the correct y coordinate for the disk
        int newY = inDisk.getY() - currHeight;
        inDisk.setY(newY);
        diskVect.push_back(inDisk);
    }
}

//remove function for the peg
Disk Peg::removeDisk()
{
    Disk retDisk = diskVect.back();
    diskVect.pop_back();
    return retDisk;
}

