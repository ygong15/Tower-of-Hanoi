// ITP 365 Fall 2022
// HW04 – Towers of Hanoi
// Name: Yuchen Gong
// Email: yuchengo@usc.edu
// Platform: Mac
#include <iostream>
#include "towers.h"

//Disk prompt
int promptForDisks()
{
    int userIn = 0;
    
    do
    {
        std::cout << "Please input the number of disks you want, valide range is " << MINDISKS << "-" << MAXDISKS << " (inclusive) >";
    std::cin >> userIn;
    }
    while(userIn > MAXDISKS || userIn < MINDISKS);
     
    
    return userIn;
}

//peg prompt
void promptForPegs(int& start, int& end)
{
    do
    {
        std::cout << "Please input a starting position for the game (1-3 inclusive) >";
        std::cin >> start;
        std::cout << "Please input an ending position for the game (1-3 inclusive & NOT the same as the starting position) > ";
        std::cin >> end;
    }
    while(start == end || start < 1 || start > 3 || end < 1 || end > 3);
}

//prompt for pausing
int promptForPause()
{
    int userIn;
    do
    {
        std::cout << "Please input the amount of time you want to pause, valide range is " << 1 << "-" << MAXPAUSELEN << " (inclusive) >";
        std::cin >> userIn;
    }
    while(userIn < 1 || userIn > MAXPAUSELEN);
    return userIn;
}

//prompt for window size
void promptForWindowSize(int& width, int& height)
{
    do
    {
        std::cout << "Please input the width for the window, valid range is " << MINSCREENWIDTH << "-" << MAXSCREENWIDTH << " (inclusive) >";
        std::cin >> width;
        std::cout << "Please input the height for the window, valid range is " << MINSCREENHEIGHT << "-" << MAXSCREENHEIGHT << " (inclusive) >";
        std::cin>>height;
    }
    while(width < MINSCREENWIDTH || width > MAXSCREENWIDTH || height < MINSCREENHEIGHT || height > MAXSCREENHEIGHT);
}

//draw function
void draw(GWindow& gw, std::vector<Peg>& pegVec, int pauseTime)
{
    //start every drawing by clearing the previous one
    gw.clear();
    //we draw each peg and each peg will call its disks' drawing
    for(Peg p : pegVec)
    {
        p.draw(gw);
    }
    //pause according to user input
    pause(pauseTime);
    
}

//move disk
void moveDisk(GWindow& gw, std::vector<Peg>& pegVec, int start, int end, int pauseTime)
{
    //since we use 1,2,3 to represent pegs -> we need to substract 1 from each peg number to get the correct peg
    Disk temp = pegVec[start-1].removeDisk();
    pegVec[end-1].addDisk(temp);
    //call draw function after a disk is moved
    draw(gw, pegVec, pauseTime);
}

//recursively solve the tower
void towerSolve(GWindow& gw, std::vector<Peg>& pegVec, int start, int end, int numDisk, int pause)
{
    //base case
    if(numDisk == 1)
    {
        //when there's only one disk, we simply move it from start to end and then return
        moveDisk(gw, pegVec, start, end, pause);
        return;
    }
    else
    {
        //when it's not the base case, we first need to calculate the position of the "other" peg
        int other = 6 - (start + end);
        //we call on towerSolve to "move" all disks before the last one on the starting peg to the other peg so that we can move the last disk on the starting peg to the end peg
        towerSolve(gw, pegVec, start, other, numDisk-1, pause);
        //now all disks above the last one on the starting peg are moved to the other peg, we can move the last disk to the ending peg
        moveDisk(gw, pegVec, start, end, pause);
        //after the last disk on the starting peg gets moved to the ending peg, we now can move all the other disks from the other peg to the ending peg by calling the towerSolve again
        towerSolve(gw, pegVec, other, end, numDisk-1, pause);
    }
}

//driver
int towerRun()
{
    //first seed the random using time
    srand(time(0));
    //the width of peg will be 20 and remain unchange
    const int PEGWIDTH = 20;
    
    //instantiate variables
    int windWidth;
    int windHeight;
    
    int numDisk;
    
    int startPeg;
    int endPeg;
    std::vector<Peg> pegVect;
    int pauseTime;
    
    //let user input appropriate values to variables
    promptForWindowSize(windWidth, windHeight);
    numDisk = promptForDisks();
    pauseTime = promptForPause();
    promptForPegs(startPeg, endPeg);
    //create a GWindow object with user inputted width and height
    GWindow gw(windWidth, windHeight);
    
    //create three pegs and push each of them into the peg vector
    //since there'll always be 3 pegs -> the location is calculated as 1/6, 1/2, and 5/6 to ensure the most evenly divition of the screen
    Peg peg1((windWidth/6), windHeight, PEGWIDTH, windHeight);
    pegVect.push_back(peg1);
    Peg peg2((windWidth/2), windHeight, PEGWIDTH, windHeight);
    pegVect.push_back(peg2);
    Peg peg3((windWidth/6*5), windHeight, PEGWIDTH, windHeight);
    pegVect.push_back(peg3);
    
    //create and push disks to the starting peg
    for(int i = 0; i < numDisk; i++)
    {
        //we default the x&y coordinate of a disk to 0
        //the disk's width will be determined by the width of the screen (divided by 6)
        //the width of a disk will get 5 percent smaller compare to its previous disk
        //the heights of disks will remain on change (1/10 of the height of the scree)
        Disk temp(0,0,(windWidth/6*(1-i*0.095)),(windHeight/10));
        //-1 to get the correct peg number
        //add disk to the starting peg
        pegVect[startPeg-1].addDisk(temp);
    }
    //draw the initial stage of the game with user inputtued amount of disks on the starting peg
    draw(gw, pegVect, pauseTime);
    //call towerSolve to sovle the tower of hanoi
    towerSolve(gw, pegVect, startPeg, endPeg, numDisk, pauseTime);
}
