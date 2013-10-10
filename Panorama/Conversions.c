//
//  Conversion.c
//  Panorama
//
//  Created by Mathieu Skulason on 10/3/13.
//  Copyright (c) 2013 Mathieu Skulason. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#import "Conversions.h"

// Converts an integer to a character string to be
// able to output integer data to the file
char* intToChar(int value)
{
    int length = 1;
    int tmpValue = value;
    
    while(tmpValue > 10)
    {
        tmpValue =  tmpValue/10;
        length++;
    }
    
    char *theCharacter =(char*)malloc(length*sizeof(char));
    
    printf("%d ", value);
    sprintf(theCharacter,"%d", value);
    
    return theCharacter;
}