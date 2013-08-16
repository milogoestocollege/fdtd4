//
//  gridinit3.c
//  fdtd3
//
//  Created by CLP on 5/24/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "fdtd3.h"

#define LOSS 0.02
#define LOSS_LAYER 180
#define EPSR    1.0

void gridInit3(Grid *g){
    double imp0 = 377.0;
    double imp0_inv = 1./377.0;
    int mm;
    
    SizeX   = 200;
    MaxTime = 400;
    Cdtds   = 1.0;
    
    ALLOC_1D(g->ez, (SizeX), double);
    ALLOC_1D(g->ceze, (SizeX), double);
    ALLOC_1D(g->cezh, (SizeX), double);
    
    ALLOC_1D(g->hy, (SizeX - 1), double);
    ALLOC_1D(g->chyh, (SizeX - 1), double);
    ALLOC_1D(g->chye, (SizeX - 1), double);
    
    #pragma omp parallel for
    /* set e field coeffs */
    for (mm = 0; mm < SizeX; mm++) {
        if (mm < 100) {
            Ceze(mm) = 1.0;
            Cezh(mm) = imp0;
        }else {
            Ceze(mm) = 1.0;
            Cezh(mm) = imp0 / EPSR ;
        }
    }

    #pragma omp parallel for    
    /*magnetic field coeffs */
    
    for (mm = 0; mm < (SizeX - 1); mm++) {
//        if (mm < LOSS_LAYER) {
            Chyh(mm) = 1.0;
            Chye(mm) = 1.0 / imp0;
//        }else {
//            Chyh(mm) = (1.0 - LOSS) / (1.0 + LOSS);
//            Chye(mm) = 1.0 * imp0_inv / (1.0 + LOSS);
//        }
    }
    
    return;
}
