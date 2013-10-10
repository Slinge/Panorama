//
//  ImageLoading.h
//  Panorama
//
//  Created by Mathieu Skulason on 10/3/13.
//  Copyright (c) 2013 Mathieu Skulason. All rights reserved.
//

#import "Types.h"

#ifndef Panorama_ImageLoading_h
#define Panorama_ImageLoading_h

// A normal image loading information
void loadImageInformation(struct ImageInfo imageInfo, char *name);

// the image to be loaded dynamically and returns a pointer
struct ImageInfo* loadData(const char *name);

// Returns a loaded image
struct ImageInfo loadImageData(struct ImageInfo imageInfo);




// sub routines to load the actual image into memory

// loading for ppm images
struct RGB** loadRGBImage(struct ImageInfo imageInfo);

// loading for pgm images
int** loadGrayImage(struct ImageInfo imageInfo);

// loading for pbm images
int** loadBlackAndWhiteImage(struct ImageInfo imageInfo);

#endif
