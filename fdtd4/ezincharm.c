//
//  ezincharm.c
//  fdtd3
//
//  Created by CLP on 5/31/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "ezinc3.h"

//global variabls but pricate to this file
static double ppw = 0, cdtds;

//get ppw
void ezIncInit(Grid *g){
    cdtds = Cdtds;
    printf("Enter points per wavelength: ");
    scanf(" %lf", &ppw);
           
    return;
}

//initialize CW source

double ezInc(double time, double location){
    if( ppw <= 0){
        fprintf(stderr, "ezInc: must call ezIncInit first\n."
                "       ppw must be positive.\n");
        exit(-1);
    }
    
    return sin(2.0 * M_PI / ppw * (cdtds * time - location));
}