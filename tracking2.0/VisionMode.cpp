/*
 * VisionMode.cpp
 *
 *  Created on: 2011. 1. 21.
 *      Author: zerom
 *  Modified on: 2022. 7. 5.
 *      Author: Yiheng Su
 */
#include <stdio.h>
#include "VisionMode.h"
#include "Action.h"
#include "ColorFinder.h"
#include "LinuxActionScript.h"

#include <iostream>
#include <vector>
using namespace std;

namespace Robot
{

    void VisionMode::Play(int color, vector<char*> names)
    {
        static int old_color = 0, color_count = 0;

        if(old_color != color || color == 0)
        {
            old_color = color;
            color_count = 0;
        }
        else
            color_count++;

        if(color_count < 15) return;

        // determine which color plays which song
        switch(color)
        {
        case (RED):
            LinuxActionScript::PlayMP3Wait(names[0]);
            break;
        case (YELLOW):
            LinuxActionScript::PlayMP3Wait(names[1]);
            break;
        case (BLUE):
            LinuxActionScript::PlayMP3Wait(names[2]);
            break;
        case (GREEN):
            LinuxActionScript::PlayMP3Wait(names[3]);
            break;
        }

        color_count = 0;
    }

}
