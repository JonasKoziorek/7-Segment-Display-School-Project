#pragma once
#include "Segment.h"

/**
 * Number structure which represents number to be displayed in Frame
 * @field num binary number representing 7 segment encoding
 * @field len legth of a number segment
 * @field type char specifying look of the number on standart output
*/
typedef struct Number{
    int num;
    int len;
    char type;
}Number;

int CreateNum(char num);
