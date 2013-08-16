//
//  tfsf.c
//  total field scattered field function
//  fdtd3
//
//  Created by CLP on 5/24/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "fdtd3.h"
#include <math.h>
#include "ezinc3.h"

static int tfsfBoundary = 0;

void tfsfInit(Grid *g){
    
    printf("Enter location of TFSF boundary: ");
    scanf(" %d", &tfsfBoundary);
    
    ezIncInit(g);//initialize source function
    
    return;
}

void tfsfUpdate(Grid *g){
    /* check if tfsfinit has run */
    if (tfsfBoundary <= 0) {
        fprintf(stderr, "tfsfinit must be called first.\n"
                "Boundary location must be a positive int.\n");
        exit(-1);
    }
    
    char filename[100], base[20]="ezinc";
    FILE *source;

    sprintf(filename, "%s.%d",base,Time);
    source = fopen(filename, "w");
    fprintf(source, "%g\n", ezInc(Time, 0));
    fclose(source);
    
    //corret hy adajcent to tfsf boundary
    
    Hy(tfsfBoundary) -= ezInc(Time, 0.0) * Chye(tfsfBoundary);
    
    // correct ez adjacnet to tfsf boundary
    
    Ez(tfsfBoundary + 1) += ezInc(Time + 0.5, -0.5);
    
    return;
}