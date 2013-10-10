//
//  InputCheck.c
//  Panorama
//
//  Created by Mathieu Skulason on 10/4/13.
//  Copyright (c) 2013 Mathieu Skulason. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#import "FileReading.h"
#import "InputCheck.h"

bool checkInputViolation(int argc, const char * argv[])
{
    bool inputViolation = true;

    for (int i = 0; i < argc; i++) {

        if(compareStrings(argv[i], "-i") || compareStrings(argv[i], "-li"))
        {
            inputViolation = false;
        }
    }

    return inputViolation;
}

struct Range fileInputRange(int argc, const char * argv[])
{
    struct Range inputRange;
    inputRange.upper = 0;
    inputRange.lower = 0;

    bool inputFound = false;
    bool foundUpper = false;
    int i;

    for( i = 0; i < argc; i++)
    {

        if (inputFound) {


             if(isFunction(&argv[i]))
             {
                 inputRange.upper = i - 1;
                 foundUpper = true;
             }
        }


         if(compareStrings(argv[i], "-i") || compareStrings(argv[i], "-li"))
         {

             if(i + 1 < argc)
             {
                 if (!isFunction(&argv[i+1]))
                 {

                     inputRange.lower = i+1;

                 }
                 else
                 {
                     printf("No input file entered in paramters \n");
                 }
             }

             inputFound = true;
         }

    }

    if(!isFunction(&argv[i]) && !foundUpper && inputFound)
    {
        inputRange.upper = i - 1;
    }

    printf("Input rang is lower: %d upper: %d \n", inputRange.lower, inputRange.upper);

    return inputRange;
}

bool isFunction(const char * argv[])
{
    if(compareStrings(argv, "-?") || compareStrings(argv, "--help") || compareStrings(argv, "-g") || compareStrings(argv, "-h") || compareStrings(argv, "-e") || compareStrings(argv, "-d") || compareStrings(argv, "-b") || compareStrings(argv, "-c") || compareStrings(argv, "-p") || compareStrings(argv, "-i") ||  compareStrings(argv, "-o") || compareStrings(argv, "-li") || compareStrings(argv, "-lo"))
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct Range fileOutputRange(int argc, const char * argv[])
{
    struct Range outputRange;
    outputRange.upper = 0;
    outputRange.lower = 0;

    bool inputFound = false;
    bool foundUpper = false;
    int i;

    for( i = 0; i < argc; i++)
    {

        if (inputFound) {


            if(isFunction(&argv[i]))
            {
                outputRange.upper = i - 1;
                foundUpper = true;
            }
        }


        if(compareStrings(argv[i], "-o") || compareStrings(argv[i], "-lo"))
        {

            if(i + 1 < argc)
            {
                if (!isFunction(&argv[i+1]))
                {

                    outputRange.lower = i+1;

                }
                else
                {
                    printf("No input file entered in paramters \n");
                }
            }

            inputFound = true;
        }

    }

    if(!isFunction(&argv[i]) && !foundUpper && inputFound)
    {
        outputRange.upper = i - 1;
    }

    printf("Input rang is lower: %d upper: %d \n", outputRange.lower, outputRange.upper);

    return outputRange;
}
