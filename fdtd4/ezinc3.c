/* functions to calculate source functions */

#include "ezinc3.h"

/* global variables but private to this file */
static double ppw = 0, cdtds, width = 0, delay;

/*get parameters from user */

void ezIncInit(Grid *g){
    
    cdtds = Cdtds;
    
//    printf("Enter ppw: ");
//    scanf(" %lf",&ppw);
    
    printf("Enter delay: ");
    scanf(" %lf",&delay);
    printf("Enter width: ");
    scanf(" %lf",&width);
    
    return;
}

/*Calculate source funtion at time and location */
double ezInc(double time, double location){
    if( width <=0 ) {
        fprintf(stderr, "ezInc: must call ezIncInit before ezInc.\n"
                "       width must be positive.\n");
        exit(-1);
    }
    
    return exp(-pow((time - delay - location / cdtds) / width, 2));
//    return sin(2*M_PI / ppw * (cdtds * time - location));
}