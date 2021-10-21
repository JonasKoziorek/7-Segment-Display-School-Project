#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Frame.h"
#include "Number.h"

/**
 * Read number from standard input as a string.
 * @param buffer pointer to buffer which will hold inputed string
 * @return buffer
*/
static char* InputNumbers(char* buffer){
    int length = 15;
    buffer = (char *)malloc(sizeof(char)*length);
    fgets(buffer,length,stdin);
    return buffer;
}

/**
 * Game loop
 * While true:
    * Read string from standard input into @var buffer, compute it's length
    * Initialize struct Frame with buffer values
    * Display Frame on standard output
    * Free allocated memory
*/
static void InputLoop(Frame *frame){
    char *buffer = NULL;
    int count = 0;
    while(1){
        printf("\nEnter number which you want to display:\n");
        buffer = InputNumbers(buffer); 
        count = strlen(buffer) - 1;

        InitFrameStruct(frame, count, buffer);
        SetNumber(frame);
        PrintFrame(frame);

        free(buffer);
        free(frame->frame);
    }

}

int main(){
    Number num = { .num = -1,
                    // length of a number segment
                    .len = 8,
                    // char type of a number segment
                    .type = '#'
                };
    Frame frame = {
                    .num = &num,
                    .count = 0,
                    .frame = NULL,
                    .framewidth = 0,
                    .frameheight = 0,
                    // spaces between numbers
                    .spaces = 3
    };
    InputLoop(&frame);  
    return 0;
}
