//
//  main.c
//  fdtd3
//
//  Created by CLP on 5/24/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "fdtd3.h"
#include </opt/local/include/fftw3.h>
#include <omp.h>

int main(int argc, const char * argv[]){

    Grid *g;
    int nthreads;
    int fftwError = 1;
    nthreads = omp_get_max_threads() - 1;
    
//    fftwError = fftw_init_threads();
    
    omp_set_num_threads(nthreads);
//    fftw_plan_with_nthreads(nthreads);

    printf("Threads: %d\n",nthreads);
    printf("Error: %d\n",fftwError);
    
    ALLOC_1D(g, 1 , Grid);
//    ALLOC_1D(g->ez, (SizeX), double);
//    ALLOC_1D(g->ceze, (SizeX), double);
//    ALLOC_1D(g->cezh, (SizeX), double);
//    
//    ALLOC_1D(g->hy, (SizeX), double);
//    ALLOC_1D(g->chyh, (SizeX), double);
//    ALLOC_1D(g->chye, (SizeX), double);

    gridInit3(g);
    abcInit(g);
    tfsfInit(g);
    snapshotInit(g);
    
    double startTime, endTime;
    
    startTime = omp_get_wtime();
    for( Time = 0; Time < MaxTime; Time ++ ){
        updateH3(g);
        tfsfUpdate(g);
        abc(g);
        updateE3(g);
        snapshot(g);
    }
    endTime = omp_get_wtime();
    
    printf("time: %e\n",(endTime - startTime));
    
    return 0;
}

