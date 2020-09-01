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
  double airDis;

printf("Origin: ");
scanf("&lf, %lf\n", &latLoc, &lonLoc );

  if(lonLoc > -91 && lonLoc < 91){
    lonlocRad = (lonLoc / 180) * 3.14;
  }
  else{
  printf("fail\n");
  }
  if(latLoc > -181 && latLoc < 181){
    latlocRad = (latLoc / 180) * 3.14;
  }
  else{
    printf("fail\n");
  }

printf("Destination: ");
scanf("%lf, %lf\n", &latDes, &lonDes );

  if(lonDes > -91 && lonDes < 91){
    londesRad = (lonDes / 180) * 3.14;
  }
  else{
    printf("fail\n");
  }
  if(latDes > -181 && latDes < 181){
    latdesRad = (latDes / 180) * 3.14;
  }
  else{
    printf("fail\n");
  }

airDis = acos((sin(latlocRad))*(sin(latdesRad)) + ((cos(latlocRad))*(cos(latdesRad))*(cos(londesRad - lonlocRad))) * (6371);

printf("Origin: (%lf, %lf)\n", latLoc, lonLoc);
printf("Destination: (%lf, %lf)\n", latDes, lonDes);
printf("Air Distance is %lf\n", airDis);

return 0;
}
