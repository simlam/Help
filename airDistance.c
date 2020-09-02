#include <stdlib.h>
#include <stdio.h>
#include <math.h>



int main(int argc, char **argv) {

  double latLoc;
  double lonLoc;
  double latlocRad;
  double lonlocRad;
  double latDes;
  double lonDes;
  double latdesRad;
  double londesRad;
  double sinlat;
  double coslat;
  double airDis;

printf("Origin: ");
scanf("%lf, %lf", &latLoc, &lonLoc);



printf("Destination: ");
scanf("%lf, %lf", &latDes, &lonDes );

//location conversion

  if(lonLoc <= -91 && lonLoc >= 91){
    printf("Fail\n");
  }
  else{
    lonlocRad = (lonLoc / 180) * 3.14;
  }

  if(latLoc <= -181 && latLoc >= 181){
    printf("Fail\n");
  }
  else{
    latlocRad = (latLoc / 180) * 3.14;
  }

//destination conversion

  if(lonDes <= -91 && lonDes >= 91){
    printf("Fail\n");
  }
  else{
    londesRad = (lonDes / 180) * 3.14;
  }
  if(latDes <= -181 && latDes >= 181){
    printf("Fail\n");
  }
  else{
    latdesRad = (latDes / 180) * 3.14;
  }


//calculations

sinlat = sin(latlocRad) * sin(latdesRad);
coslat = cos(latlocRad) * cos(latdesRad) * cos(londesRad - lonlocRad);
airDis = acos(sinlat + coslat) * 6371;

//outputs

printf("Origin: (%lf, %lf)\n", latLoc, lonLoc);
printf("Destination: (%lf, %lf)\n", latDes, lonDes);
printf("Air Distance is %lf kms\n", airDis);

//Margin of error based on value used for pi

return 0;
}
