#pragma once
#include "Number.h"

/**
 * Frame structure represents 2D matrix which holds numbers to be displayed on standart output
 * @field num pointer to first Number in array of Numbers
 * @field count length of num array
 * @field frame 2D matrix which holds chars to be displayed
 * @field framewidth, frameheight: dimensions of frame
 * @field spaces how many empty chars should be between displayed numbers 
*/
typedef struct Frame{
    Number *num;
    int count;
    char* frame;
    int framewidth;
    int frameheight;
    int spaces;
}Frame;

char* InitFrame(Frame *frame);

void InitFrameStruct(Frame *frame, int count, char *buffer);

void ResetFrame(Frame *frame);

void PrintFrame(Frame *frame);

void SetHorizontal(Frame *frame, int xcoord, int ycoord);

void SetHorizontal(Frame *frame, int xcoord, int ycoord);

Number* InitNumbers(Frame *frame, char *buffer);

void SetNumber(Frame *frame);
