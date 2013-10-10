//
//  Types.h
//  Panorama
//
//  Created by Mathieu Skulason on 10/3/13.
//  Copyright (c) 2013 Mathieu Skulason. All rights reserved.
//

#ifndef Panorama_Types_h
#define Panorama_Types_h

#define PBM "P1"
#define PGM "P2"
#define PPM "P3"

// The filetypes
typedef enum
{
    kFileTypePBM,
    kFileTypePGM,
    kFileTypePPM,
    kFileTypeNone
    
} FileTypes;

// size of the image
struct ImageSize
{
    int height;
    int width;
};

// Struct for image information
struct ImageInfo
{
    int height;
    int width;
    int maxValue;
    char *imageName;
    FILE *file;
    FileTypes fileType;
    int **imageData;
    struct RGB **imageRGBData;
};

// gives a range from lower to upper
struct Range
{
    int lower;
    int upper;
};

// Struct for RGB images
struct RGB
{
    int red;
    int green;
    int blue;
};

#endif
