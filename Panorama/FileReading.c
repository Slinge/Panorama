//
//  FileReading.c
//  Panorama
//
//  Created by Mathieu Skulason on 10/3/13.
//  Copyright (c) 2013 Mathieu Skulason. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#import "Types.h"
#import "FileReading.h"

char* readCharDynamically(struct ImageInfo imageInfo)
{
    char character = getc(imageInfo.file);
    int i = 0;
    char *tmpString = NULL;
    
    if(character == '\n' || character == ' ')
    {
        return readCharDynamically(imageInfo);
    }
    
    // Check if the check for # is necessary make safe
    while(character != '\n' && character != ' ')
    {
        if(tmpString == NULL)
        {
            tmpString = malloc(1*sizeof(char));
        }
        else
        {
            tmpString = realloc(tmpString,(i+1)*sizeof(char));
        }
        
        tmpString[i] = character;
        character =  getc(imageInfo.file);
        i++;
    }
    
    tmpString = realloc(tmpString, (i+1)*sizeof(char));
    tmpString[i] = '\0';
    
    return tmpString;
}

bool compareStrings(const char *originalString,const char *comparisonString)
{
    int length;
    int i;
    
    if(strlen(originalString) != strlen(comparisonString))
    {
        return false;
    }
    else
    {
        length = (int)strlen(originalString);
    }
    
    bool isEqual = true;
    
    for(i = 0; i < length && isEqual ; i++)
    {
        if(originalString[i] != comparisonString[i])
        {
            isEqual = false;
        }
    }
    
    return isEqual;
    
}

FileTypes determineFileType(char *fileTypeName)
{
    FileTypes fileType;
    
    if(compareStrings(fileTypeName,PBM))
    {
        fileType = kFileTypePBM;
        printf("File Type is PBM \n");
    }
    else if(compareStrings(fileTypeName, PGM))
    {
        fileType = kFileTypePGM;
        printf("File Type is PGM \n");
    }
    else if(compareStrings(fileTypeName, PPM))
    {
        fileType = kFileTypePPM;
        printf("File Type is PPM \n");
    }
    else
    {
        printf("No valid filetype found");
        fileType = kFileTypeNone;
    }
    
    return fileType;
}


////////////////// Functions to read pixel data /////////////////////


int valueForSingleCharacter(struct ImageInfo imageInfo)
{
    char character = getc(imageInfo.file);
    
    if(character == '\n' || character == ' ')
    {
        return valueForSingleCharacter(imageInfo);
    }
    else
    {
        int i = character - '0';
        
        return i;
    }
}

int valueForCharacter(struct ImageInfo imageInfo)
{
    char character = getc(imageInfo.file);
    int i = 0;
    char *tmpString = NULL;
    
    if(character == '\n' || character == ' ')
    {
        return valueForCharacter(imageInfo);
    }
    
    // Check if the check for # is necessary make safe
    while(character != '\n' && character != ' ')
    {
        if(tmpString == NULL)
        {
            tmpString = malloc(1*sizeof(char));
        }
        else
        {
            tmpString = realloc(tmpString,(i+1)*sizeof(char));
        }
        
        tmpString[i] = character;
        character =  getc(imageInfo.file);
        i++;
    }
    
    tmpString = realloc(tmpString, (i+1)*sizeof(char));
    tmpString[i] = '\0';
    
    int k = 0;
    int value = 0;
    
    for(k = 0; k < i; k++)
    {
        value = (tmpString[k] - '0') + value*10;
    }
        
    return value;
}

