//
//  InputCheck.h
//  Panorama
//
//  Created by Mathieu Skulason on 10/4/13.
//  Copyright (c) 2013 Mathieu Skulason. All rights reserved.
//

#import "Types.h"

#ifndef Panorama_InputCheck_h
#define Panorama_InputCheck_h

// checks for various input violation
bool checkInputViolation(int argc,const char * argv[]);

// range of the input of the files in the arguments
struct Range fileInputRange(int argc, const char * argv[]);

// range for the output of the file in the arguments
struct Range fileOutputRange(int argc, const char * argv[]);


bool isFunction(const char * argv[]);

#endif
