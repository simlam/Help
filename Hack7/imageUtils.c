#include <stdlib.h>
#include <stdio.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "imageUtils.h"

Pixel** loadImage(const char* filePath, int* height, int* width) {
    int x, y, n;
    unsigned char* data = stbi_load(filePath, &x, &y, &n, 4); //4 = force RGBA channels
    *height = y;
    *width = x;

    //contiguous allocation:
    Pixel** image = (Pixel**)malloc(sizeof(Pixel*) * y);
    image[0] = (Pixel*)malloc(sizeof(Pixel) * (y * x));
    for (int i = 1; i < y; i++) {
        image[i] = (*image + (x * i));
    }

    int rowIndex = 0;
    int colIndex = 0;
    for (int i = 0; i < (x * y * 4); i += 4) { //for each row
        image[rowIndex][colIndex].red = data[i + 0];
        image[rowIndex][colIndex].green = data[i + 1];
        image[rowIndex][colIndex].blue = data[i + 2];
        colIndex++;
        if (colIndex == x) {
            //go to next row, reset column
            rowIndex++;
            colIndex = 0;
        }
    }
    stbi_image_free(data);
    return image;
}

void saveImage(const char* fileName, Pixel** image, int height, int width) {

    // Convert height x width Pixel array to single array with
    // 3 (RGB) channels, ignoring the alpha channel and assume 100% opaque
    unsigned char* data = (unsigned char*)malloc(height * width * 3);
    int x = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            data[x + 0] = image[i][j].red;
            data[x + 1] = image[i][j].green;
            data[x + 2] = image[i][j].blue;
            x += 3;
        }
    }
    //write
    stbi_write_jpg(fileName, width, height, 3, data, 100);
    free(data);
    return;
}

Pixel** copyImage(Pixel** image, int height, int width) {
    //TODO: implement
    //This is the same as the reversing functiosn we wrote not too long ago
    //All of these bitch ass functions use that core block of code in some way

    
    Pixel** copyImage = (Pixel**)malloc(sizeof(Pixel*) * height);
    copyImage[0] = (Pixel*)malloc(sizeof(Pixel) * (height * width));

    int i;
    for (i = 1; i < height; i++)
    {
        copyImage[i] = (*copyImage + (width * i));
    }

    int j,
        k;
    for (j = 0; j < height; j++)
    {
        for (k = 0; k < width; k++) 
        {
            copyImage[j][k] = image[j][k];
        }
    }

    return copyImage;

}

void flipHorizontal(Pixel** image, int height, int width) {
    //TODO: implement



    return;
}

void flipVertical(Pixel** image, int height, int width) {
    //TODO: implement
    return;
}

Pixel** rotateClockwise(Pixel** image, int height, int width) {
    //TODO: implement
}