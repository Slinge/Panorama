#include "convolution.h"
#include <stdio.h>
#include <stdlib.h>

ImageInfo convolution(ImageInfo picture, int** matrix,int d){
    if(picture.imageData != NULL ){
        int** image[picture.width][picture.height];
        image = convolBW(picture.imageData,picture.width,picture.height,matrix,d);
        picture.imageData = image;
    }
    else if(picture.imageRGBdata != NULL){
        RGB** imageRGB[picture.width][picture.height];
        imageRGB = convolRGB(picture.imageRGBdata,picture.width,picture.height,matrix,d);
        picture.imageRGBdata = imageRGB;
    }
    return picture;
}

int** convolBW(int** image ,int w,int h,int** matrix,int d){
    int** result = image;
    for(int i=0; i< w; i++){
        for(int j=0;j<h;j++){
            result[i][j]=(image[i][j])*(matrix[1][1]);
            if ((i!=0)&&(j!=0))
                result[i][j]+= (image[i-1][j-1])*(matrix[0][0]);
            if (i!=0)
                result[i][j]+= (image[i-1][j])*(matrix[0][1]);
            if((i!=0)&&(j!=h-1))
                 result[i][j]+= (image[i-1][j+1])*(matrix[0][2]);
            if (j!=0)
                result[i][j]+= (image[i][j-1])*(matrix[1][0]);
            if (i!=w-1)
                 result[i][j]+= (image[i+1][j])*(matrix[1][2]);
            if ((i!=w-1)&&(j!=0))
                 result[i][j]+= (image[i+1][j-1])*(matrix[2][0]);
            if  (j!=h-1)
                 result[i][j]+= (image[i][j+1])*(matrix[2][1]);
            if ((i!=w-1)&&(j!=h-1))
                 result[i][j]+= (image[i+1][j+1])*(matrix[2][2]);
            result[i][j] = result[i][j]/d;
            if (result[i][j] > 255)
                result[i][j] = 255;
        }
    }
    return result;
}


RGB** convolRGB(RGB** image,int w,int h,int** matrix,int d){
    RGB** result = image;
    for(int i=0; i< w; i++){
        for(int j=0;j<h;j++){
            (result[i][j]).R+=(image[i][j]).R*(matrix[1][1]);
            (result[i][j]).G+=(image[i][j]).G*(matrix[1][1]);
            (result[i][j]).B+=(image[i][j]).B*(matrix[1][1]);
            if ((i!=0)&&(j!=0))
                (result[i][j]).R+=(image[i-1][j-1]).R*(matrix[0][0]);
                (result[i][j]).G+=(image[i-1][j-1]).G*(matrix[0][0]);
                (result[i][j]).B+=(image[i-1][j-1]).B*(matrix[0][0]);
            if (i!=0)
                (result[i][j]).R+=(image[i-1][j]).R*(matrix[0][1]);
                (result[i][j]).G+=(image[i-1][j]).G*(matrix[0][1]);
                (result[i][j]).B+=(image[i-1][j]).B*(matrix[0][1]);
            if((i!=0)&&(j!=h-1))
                (result[i][j]).R+=(image[i-1][j+1]).R*(matrix[0][2]);
                (result[i][j]).G+=(image[i-1][j+1]).G*(matrix[0][2]);
                (result[i][j]).B+=(image[i-1][j+1]).B*(matrix[0][2]);
            if (j!=0)
                (result[i][j]).R+=(image[i][j-1]).R*(matrix[1][0]);
                (result[i][j]).G+=(image[i][j-1]).G*(matrix[1][0]);
                (result[i][j]).B+=(image[i][j-1]).B*(matrix[1][0]);
            if (i!=w-1)
                (result[i][j]).R+=(image[i+1][j]).R*(matrix[1][2]);
                (result[i][j]).G+=(image[i+1][j]).G*(matrix[1][2]);
                (result[i][j]).B+=(image[i+1][j]).B*(matrix[1][2]);
            if ((i!=w-1)&&(j!=0))
                (result[i][j]).R+=(image[i+1][j-1]).R*(matrix[2][0]);
                (result[i][j]).G+=(image[i+1][j-1]).G*(matrix[2][0]);
                (result[i][j]).B+=(image[i+1][j-1]).B*(matrix[2][0]);
            if  (j!=h-1)
                (result[i][j]).R+=(image[i][j+1]).R*(matrix[2][1]);
                (result[i][j]).G+=(image[i][j+1]).G*(matrix[2][1]);
                (result[i][j]).B+=(image[i][j+1]).B*(matrix[2][1]);
            if ((i!=w-1)&&(j!=h-1))
                (result[i][j]).R+=(image[i+1][j-1]).R*(matrix[2][2]);
                (result[i][j]).G+=(image[i+1][j-1]).G*(matrix[2][2]);
                (result[i][j]).B+=(image[i+1][j-1]).B*(matrix[2][2]);
            (result[i][j]).R=(result[i][j]).R/d;
            (result[i][j]).G=(result[i][j]).G/d
            (result[i][j]).B=(result[i][j]).B/d;
            if (result[i][j].R > 255)
                result[i][j].R = 255;
            if (result[i][j].G > 255)
                result[i][j].G = 255;
            if (result[i][j].B > 255)
                result[i][j].B = 255;
                result[i][j].B = 255;
        }
    }
    return result;
}

