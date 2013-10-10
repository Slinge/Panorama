//
//  ImageLoading.c
//  Panorama
//
//  Created by Mathieu Skulason on 10/3/13.
//  Copyright (c) 2013 Mathieu Skulason. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#import "ImageLoading.h"
#import "Types.h"
#import "FileReading.h"
#import "FileExporting.h"
#import "Conversions.h"


void loadImageInformation(struct ImageInfo imageInfo, char *name)
{
    printf("%s \n", name);
    
    imageInfo.imageName = malloc(sizeof(name));
    imageInfo.imageName = name;
    
    imageInfo.file = fopen(name, "r");
    
    if(imageInfo.file == NULL)
    {
        printf("ERROR couldn't find specified file \n");
        
    }
    else
    {
        printf("File Found \n");
        
        char *filetype;
        
        filetype = readCharDynamically(imageInfo);
        printf("The File Type string: %s \n", filetype);
        
        imageInfo.fileType = determineFileType(filetype);
        
        sscanf((readCharDynamically(imageInfo)),"%d", &imageInfo.width);
        sscanf((readCharDynamically(imageInfo)), "%d", &imageInfo.height);
        printf("image widht: %d \n", imageInfo.width);
        printf("image height: %d \n", imageInfo.height);
        
    }
    
    switch(imageInfo.fileType)
    {
        case kFileTypePBM:
            
            imageInfo.imageData = loadBlackAndWhiteImage(imageInfo);
            printf("Exporting \n");
            exportImage("demo2.pbm", imageInfo);
            
            break;
            
        case kFileTypePGM:
            
            sscanf((readCharDynamically(imageInfo)), "%d", &imageInfo.maxValue);
            printf("Max Value: %d \n", imageInfo.maxValue);
            imageInfo.imageData = loadGrayImage(imageInfo);
            exportImage("demo3.pgm", imageInfo);
            
            break;
            
        case kFileTypePPM:
            sscanf((readCharDynamically(imageInfo)), "%d", &imageInfo.maxValue);
            printf("Max Value: %d \n", imageInfo.maxValue);
            imageInfo.imageRGBData = loadRGBImage(imageInfo);
            printf("Image loaded");
            exportImage("demo2.ppm", imageInfo);
            
            break;
            
        case kFileTypeNone:
            
            break;
    }
    
}


struct ImageInfo* loadData(const char *name)
{
    struct ImageInfo *imageInfo = malloc(sizeof(struct ImageInfo));
    
    imageInfo->imageName = malloc(sizeof(name));
    imageInfo->imageName = name;
    
    imageInfo->file = fopen(name, "r");
    
    if(imageInfo->file == NULL)
    {
        printf("ERROR couldn't find specified file \n");
    }
    else
    {
        printf("File Found \n");

        char *filetype;
        
        filetype = readCharDynamically(*imageInfo);
        printf("The File Type string: %s \n", filetype);
        
        imageInfo->fileType = determineFileType(filetype);
        
        free(filetype);
        
        char *width = readCharDynamically(*imageInfo);
        char *height = readCharDynamically(*imageInfo);
        
        sscanf(width,"%d", &imageInfo->width);
        sscanf(height, "%d", &imageInfo->height);
        
        free(width);
        free(height);
        
        printf("image widht: %d \n", imageInfo->width);
        printf("image height: %d \n", imageInfo->height);

        
    }
    
    switch (imageInfo->fileType) {
        
        case kFileTypePBM:
            
            imageInfo->imageData = loadBlackAndWhiteImage(*imageInfo);
            
            break;
            
        case kFileTypePGM:
            
            sscanf(readCharDynamically(*imageInfo), "%d", &imageInfo->maxValue);
            printf("Max Value: %d \n", imageInfo->maxValue);
            imageInfo->imageData = loadGrayImage(*imageInfo);
            
            break;
            
        case kFileTypePPM:
            
            sscanf(readCharDynamically(*imageInfo), "%d", &imageInfo->maxValue);
            printf("Max Value: %d \n", imageInfo->maxValue);
            imageInfo->imageRGBData = loadRGBImage(*imageInfo);
            
            break;
            
        default:
            break;
    }
    
    fclose(imageInfo->file);
    
    return imageInfo;
}


int** loadBlackAndWhiteImage(struct ImageInfo imageInfo)
{
    int **data;
    
    data = (int **)malloc(imageInfo.height*sizeof(int *));
    
    int length = 0;
    
    if(data)
    {
        for(length = 0; length < imageInfo.height; length++)
        {
            data[length] = (int *)malloc(sizeof(int)*imageInfo.width);
        }
    }
    
    int i;
    int k;
    
    
    for(i = 0; i < imageInfo.height; i++)
    {
        for(k = 0; k < imageInfo.width; k++)
        {
            
            data[i][k] = valueForSingleCharacter(imageInfo);
        }
    }
    
    
    return data;
}

int** loadGrayImage(struct ImageInfo imageInfo)
{
    int **data;
    
    data = (int **)malloc(imageInfo.height*sizeof(int *));
    
    int length = 0;
    
    if(data)
    {
        for(length = 0; length < imageInfo.height; length++)
        {
            data[length] = (int *)malloc(sizeof(int)*imageInfo.width);
        }
    }
    
    int i;
    int k;
    
    
    for(i = 0; i < imageInfo.height; i++)
    {
        for(k = 0; k < imageInfo.width; k++)
        {
            data[i][k] = valueForCharacter(imageInfo);
        }
    }
    
    return data;
    
}

struct RGB** loadRGBImage(struct ImageInfo imageInfo)
{
    
    struct RGB **data;
    
    data = (struct RGB **)malloc(imageInfo.height*sizeof(struct RGB *));
    
    int length = 0;
    
    if(data)
    {
        for(length = 0; length < imageInfo.height; length++)
        {
            data[length] = (struct RGB *)malloc(sizeof(struct RGB)*imageInfo.width);
        }
    }
    
    int i;
    int k;
    
    
    for(i = 0; i < imageInfo.height; i++)
    {
        for(k = 0; k < imageInfo.width; k++)
        {
            data[i][k].red = valueForCharacter(imageInfo);
            data[i][k].green = valueForCharacter(imageInfo);
            data[i][k].blue = valueForCharacter(imageInfo);
        }
    }
    
    
    return data;
}

