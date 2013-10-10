//
//  main.c
//  Panorama
//
//  Created by Mathieu Skulason on 10/2/13.
//  Copyright (c) 2013 Mathieu Skulason. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#import "FileReading.h"
#import "ImageLoading.h"
#import "Types.h"
#import "InputCheck.h"

// Basic Console output
void consoleOutput();
void release(struct ImageInfo *imageInfo);

int main(int argc, const char * argv[])
{

    // insert code here...
    
    consoleOutput();
    
    if(checkInputViolation(argc, argv))
    {
        printf("INPUT VIOLATION \n");
    }
    else
    {
        printf("NO INPUT VIOLATION \n");
        
        struct Range fileRange = fileInputRange(argc, argv);
        
        struct ImageInfo *images = (struct ImageInfo*)malloc((fileRange.upper - fileRange.lower + 1)*sizeof(struct ImageInfo));
        
        int k = fileRange.lower;
        
        for(int i = 0; fileRange.lower <= k && fileRange.upper >= k; i++)
        {
            printf("Loading image: %d \n", i+1);
            
            images[i] = *loadData(argv[k]);
            
            k++;
        }
        
    }
    
    return 0;
}


void consoleOutput()
{
    printf("PANORAMA \n\n");
    
    printf("NAME \n");
    printf("    panorama \n\n");
    
    printf("SYNOPSIS \n");
    printf("    panorama [OPTION...] \n\n");
    
    printf("DESCRIPTION \n");
    printf("    Image manipulation helper to create panorama \n\n");
    
    printf("USAGE \n");
    printf("    Usage : panorama[OPTION...] \n\n");
    
    printf("    Help options \n");
    printf("        -?, --help      shows this help message \n \n");
    
    printf("    General Options \n\n");
    
    printf("    Working On Single File \n");
    printf("        -i file         define the input file \n");
    
}

void release(struct ImageInfo *imageInfo)
{
    if (imageInfo->imageData != NULL) {
        
        for (int i = 0; i < imageInfo->height; i++) {
            free(imageInfo->imageData[i]);
        }
        free(imageInfo->imageData);
    }
    
    if(imageInfo->imageName != NULL)
    {
        free(imageInfo->imageName);
    }
    
    if(imageInfo->imageRGBData != NULL)
    {
        for(int i = 0; i < imageInfo->height; i++)
        {
            free(imageInfo->imageRGBData[i]);
        }
        free(imageInfo->imageRGBData);
    }
    
    free(imageInfo);
}
