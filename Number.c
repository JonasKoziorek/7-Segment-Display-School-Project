#include "Number.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Assigns corresponding segments based of inputed char
 * @param num number to be activated
*/
int CreateNum(char num){
    switch (num){
        case '0':
            return 0b0111111;

        case '1':
            return 0b0000110;

        case '2':
            return 0b1011011;

        case '3':
            return 0b1001111;

        case '4':
            return 0b1100110;

        case '5':
            return 0b1101101;

        case '6':
            return 0b1111101;

        case '7':
            return 0b0000111;

        case '8':
            return 0b1111111;

        case '9':
            return 0b1101111;
        default:
            return -1;
    }
}
