//
//  FileExporting.c
//  Panorama
//
//  Created by Mathieu Skulason on 10/3/13.
//  Copyright (c) 2013 Mathieu Skulason. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#import "Types.h"
#import "FileExporting.h"
#import "Conversions.h"

void exportImage(char *name, struct ImageInfo imageInfo)
{
    FILE *outputFile = fopen(name, "w");
    
    int i;
    int k;
    
    if(outputFile == NULL)
    {
        printf("Error can't write the file");
    }
    else
    {
        switch(imageInfo.fileType)
        {
            case kFileTypePBM:
                
                fputs("P1 \n", outputFile);
                fputs(intToChar(imageInfo.width), outputFile);
                fputs(" ", outputFile);
                fputs(intToChar(imageInfo.height), outputFile);
                fputs("\n", outputFile);
                
                
                for(i = 0; i < imageInfo.height; i++)
                {
                    for(k = 0; k < imageInfo.width; k++)
                    {
                        fputs(intToChar(imageInfo.imageData[i][k]), outputFile);
                    }
                }
                
                
                break;
                
            case kFileTypePGM:
                
                fputs("P2 \n", outputFile);
                fputs(intToChar(imageInfo.width), outputFile);
                fputs(" ", outputFile);
                fputs(intToChar(imageInfo.height), outputFile);
                fputs("\n", outputFile);
                fputs(intToChar(imageInfo.maxValue), outputFile);
                fputs("\n", outputFile);
                
                for(i = 0; i < imageInfo.height; i++)
                {
                    for(k = 0; k < imageInfo.width; k++)
                    {
                        fputs(intToChar(imageInfo.imageData[i][k]), outputFile);
                        fputs("\n", outputFile);
                    }
                }
                
                break;
                
            case kFileTypePPM:
                
                fputs("P3 \n", outputFile);
                fputs(intToChar(imageInfo.width), outputFile);
                fputs(" ", outputFile);
                fputs(intToChar(imageInfo.height), outputFile);
                fputs("\n", outputFile);
                fputs(intToChar(imageInfo.maxValue), outputFile);
                fputs("\n", outputFile);
                
                for(i = 0; i < imageInfo.height; i++)
                {
                    for(k = 0; k < imageInfo.width; k++)
                    {
                        fputs(intToChar(imageInfo.imageRGBData[i][k].red), outputFile);
                        fputs("\n", outputFile);
                        fputs(intToChar(imageInfo.imageRGBData[i][k].green), outputFile);
                        fputs("\n", outputFile);
                        fputs(intToChar(imageInfo.imageRGBData[i][k].blue), outputFile);
                        fputs("\n", outputFile);
                    }
                }
                
                break;
        }
    }
    
    fclose(outputFile);
}

