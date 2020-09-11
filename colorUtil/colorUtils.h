/*This is the header of the colorUtils*/
/*The names will be here*/

/**
 * Returns the maximum value among the three
 * given integer values.
 */

//This is the lightness technique

int max(int x, int y, int z);

//Return the minimum value among the three given interger values

int min(int x, int y, int z);

int toGrayScaleLightness(int r, int g, int b);

/**
 * Returns a gray-scaled RGB value of the three
 * given RGB values using the average technique.
 *
 */

int toGrayScaleAverage(int r, int g, int b);

//This is the luminosity technique

int toGrayScaleLuminosity(int r, int g, int b);

//Sepias

int toSepiaRed(int r, int g, int b);

int toSepiaGreen(int r, int g, int b);

int toSepiaBlue(int r, int g, int b);
