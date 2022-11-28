// ITP 365 Fall 2022
// HW04 – Towers of Hanoi
// Name: Yuchen Gong
// Email: yuchengo@usc.edu
// Platform: Mac

#pragma once

#include "disk.h"
#include "peg.h"
#include "gwindow.h"

#include <vector>

const int MINSCREENWIDTH = 800;
const int MINSCREENHEIGHT = 600;
const int MAXSCREENWIDTH = 4096;
const int MAXSCREENHEIGHT = 2160;
const int MINDISKS = 2;
const int MAXDISKS = 10;
const int NUMPEGS = 3;
const int MAXPAUSELEN = 1000000;

// Name:
//       promptForDisks
// Input:
//        None
// Output:
//        a int
// Side effects:
//        uses cout to prompt user
// Summary:
//        returns a int between 2 to 10 indicating the number of disks for the game
int promptForDisks();

// Name:
//       promptForPegs
// Input:
//        two integer referrences
// Output:
//        none
// Side effects:
//        setting the start and end integer referrences to allowed value
// Summary:
//        prompt user to set a start and an end position for the game (cannot be the same and can only be in range of 1-3)
void promptForPegs(int& start, int& end);

// Name:
//       promptForPause
// Input:
//        None
// Output:
//        a int
// Side effects:
//        uses cout to prompt users
// Summary:
//        returns a int between MINPAUSE and MAXPAUSE indicating the time to pause between each move
int promptForPause();

// Name:
//       promptForWindowSize
// Input:
//        two integer referrences
// Output:
//        none
// Side effects:
//        setting the width and height to appropriate value
// Summary:
//        setting the passed in interger referrences to appropriate values
void promptForWindowSize(int& width, int& height);

// Name:
//       draw
// Input:
//        a GWindow, a Peg vector, and an integer
// Output:
//        none
// Side effects:
//        clearing the gwindow, draw pegs and disks, and pausing
// Summary:
//        drawing pegs and associated disks
void draw(GWindow& gw, std::vector<Peg>& pegVec, int pause);

// Name:
//       moveDisk
// Input:
//        GWindow object, peg vector, int start position, int end position, int pause time
// Output:
//        none
// Side effects:
//        poping off the top most disk from the starting peg and add it to the end peg
//        call draw function afterwards
// Summary:
//         moving the top most disk from the start peg to the end position peg
void moveDisk(GWindow& gw, std::vector<Peg>& pegVec, int start, int end, int pauseTime);

// Name:
//       towerSolve
// Input:
//        GWindow object, peg vector, int start position, int end position, int number of disk, int pause time
// Output:
//        none
// Side effects:
//        solving the tower of hanoi
// Summary:
//        using the six inputs to recursively solve the tower of hanoi
void towerSolve(GWindow& gw, std::vector<Peg>& pegVec, int start, int end, int numDisk, int pause);

// Name:
//       towerRun
// Input:
//        None
// Output:
//        a int
// Side effects:
//        call towerSlver
// Summary:
//        solve and graph the tower of hanoi
int towerRun();

