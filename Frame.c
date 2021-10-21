#include "Frame.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Allocates memory for Frame.frame
 * @param frame holds values such as framewidth, frameheight
 * @return pointer to memory
*/
char* InitFrame(Frame *frame){
    int framewidth = frame->framewidth;
    int frameheight = frame->frameheight;

    char* newframe = (char*)malloc(sizeof(char)* framewidth * frameheight );
    for( int i = 0; i < framewidth * frameheight ; i++){
        newframe[i] =  ' ';
    }

    return newframe;
}

/**
 * Initialize the whole Frame structure with corresponding values
 * @param frame Frame to be changed
 * @param count number of digits in buffer
 * @param buffer array that stores digits to be printed
*/
void InitFrameStruct(Frame *frame, int count, char *buffer){
        int space = frame->spaces;
        int len = frame->num->len;
        frame->count = count;
        frame->framewidth = count * (len + space);
        frame->frameheight = 2 * len - 1;
        frame->num = InitNumbers(frame, buffer);
        frame->frame = InitFrame(frame);
}

/**
 * Sets all values of Frame.frame to empty space
 * @param frame Frame to be changed
*/
void ResetFrame(Frame *frame){
    int framewidth = frame->framewidth;
    int frameheight = frame->frameheight;
    for( int i = 0; i < framewidth * frameheight ; i++){
        frame->frame[i] = ' ';
    }
}

/**
 * Print Frame to standart output
 * @param frame Frame to be displayed
*/
void PrintFrame(Frame *frame){
    int framewidth = frame->framewidth;
    int frameheight = frame->frameheight;
    for( int i = 0; i < frameheight; i++){
        for( int j = 0; j <  framewidth; j++){
            printf("%c", frame->frame[i * framewidth + j] );
        }
        printf("\n");
    }
}

/**
 * Create horizontal segment in Frame.frame
 * @param frame Frame to be changed
 * @param xcoord x coordinate in Frame.frame
 * @param ycoord y coordinate in Frame.frame
 * @var len length of a segment
 * Values in Frame.frame from (xcoord, ycoord) to (xcoord + len, ycoord) will be changed to @var type
*/
void SetHorizontal(Frame *frame, int xcoord, int ycoord){
    int framewidth = frame->framewidth;
    int frameheight = frame->frameheight;
    int len = frame->num->len;
    char type = frame->num->type;
    for( int j = 0; j < len; j++){
        if( j == 0 || j == len - 1 ){
            frame->frame[ ycoord * framewidth + xcoord + j ] = ' ';
        }
        else{
            frame->frame[ ycoord * framewidth + xcoord + j ] = type; 
        }
    }
}

/**
 * Create vertical segment in Frame.frame
 * @param frame Frame to be changed
 * @param xcoord x coordinate in Frame.frame
 * @param ycoord y coordinate in Frame.frame
 * @var len length of a segment
 * Values in Frame.frame from (xcoord, ycoord) to (xcoord, ycoord + len) will be changed to @var type
*/
void SetVertical(Frame *frame, int xcoord, int ycoord){
    int framewidth = frame->framewidth;
    int len = frame->num->len ;
    int height = ycoord + len;
    int type = frame->num->type;
    for( int i = ycoord; i < height; i++){
        if( i == ycoord || i == height - 1 ){
            frame->frame[ i * framewidth + xcoord ] = ' ';
        }
        else{
            frame->frame[ i * framewidth + xcoord ] = type; 
        }
    }
}

/**
 * Allocate memory for Numbers in Frame.nums and set their value to values in buffer
 * @param frame Frame to be changed
 * @param buffer array containing values to set
 * @return numbers allocated array of Numbers 
*/
Number* InitNumbers(Frame *frame, char *buffer){
    int len = frame->num->len;
    char type = frame->num->type;
    int count = frame->count;
    Number* numbers = (Number*)malloc(sizeof(Number) * count);
    for( int i = 0; i < count; i++){
        numbers[i].num = CreateNum(buffer[i]);
        numbers[i].len = len;
        numbers[i].type = type;
    }
    return numbers;
}

/**
 * Reads Frame.num[i] and activates segments which they contain as true
 * @param frame Frame to be changed
*/
void SetNumber(Frame *frame){
    int len = frame->num->len;
    int count = frame->count;
    int space = frame->spaces; 
    int frameheight = frame->frameheight;
    Number* current_number = frame->num;

    const int number_of_segments = 7;
    int mask = 0b0000001;
    for( int i = 0; i < count; i++){
        int segments_to_activate[ number_of_segments ];
        for( int j = 0; j < number_of_segments; j++){
           segments_to_activate[j] = current_number[i].num & (mask << j);
        }

        // segment a
        if(segments_to_activate[a]) SetHorizontal(frame,i * (len + space), 0);
        // segment b
        if(segments_to_activate[b]) SetVertical(frame,i * (len+ space) + len-1, 0);
        // segment c
        if(segments_to_activate[c]) SetVertical(frame,i * (len + space) + len-1,len -1);
        // segment d
        if(segments_to_activate[d]) SetHorizontal(frame, i * (len + space), 2 * len - 2);
        // segment e
        if(segments_to_activate[e]) SetVertical(frame, i * (len + space), len - 1);
        // segment f
        if(segments_to_activate[f]) SetVertical(frame, i * (len + space), 0);
        // segment g
        if(segments_to_activate[g]) SetHorizontal(frame, i * (len + space), frameheight / 2);
    }
}
