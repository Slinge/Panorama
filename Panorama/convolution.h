#IFNDEF _CONVOLUTION
#DEFINE _CONVOLUTION
#include <image.h>

ImageInfo convolution(Imageinfo,int** ,int);//Fonction de convolution g�n�rale, en param�tres : L'image, la matrice et le diviseur.
int** convolBW(int**,int,int,int**,int);//Fonction de convolution niveau de gris. en param�tres : matrice image, hauteur, largeur, matrice de convolution et diviseur
RGB** convolRGB(RGB**,int,int,int**,int);//Fonction de convolution couleur. en param�tres : matrice image couleur, hauteur, largeur, matrice de convolution et diviseur
#endif
