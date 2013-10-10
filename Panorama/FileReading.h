//
//  FileType.h
//  Panorama
//
//  Created by Mathieu Skulason on 10/3/13.
//  Copyright (c) 2013 Mathieu Skulason. All rights reserved.
//

#include <stdbool.h>

#import "Types.h"

#ifndef Panorama_FileType_h
#define Panorama_FileType_h

// Creates a char array and allocates dynamic memory for it and returns a pointer to it
char* readCharDynamically(struct ImageInfo imageInfo);

// Returns a certain file type for the image from the char string
FileTypes determineFileType(char *fileTypeName);

// Compares to strings and returns true if they are exactly the same
bool compareStrings(const char *originalString,const char *comparisonString);

// Functions to read the pixel data into memory
int valueForCharacter(struct ImageInfo imageInfo);

// Function to read the pixel data for one character at a time into memory
int valueForSingleCharacter(struct ImageInfo imageInfo);

#endif
