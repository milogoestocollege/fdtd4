//
//  update3.c
//  fdtd3
//
//  Created by CLP on 5/24/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "fdtd3.h"
#include <omp.h>
/* update H field*/

void updateH3(Grid *g){
    int mm;
//    int nthreads = 7;
//    omp_set_num_threads(nthreads);

    
    #pragma omp parallel for
    for (mm = 0; mm < (SizeX - 1); mm++) {
//        if (mm == 0 && Time == 1) {//check to see if omp is working
//                    printf("threads actuall: %d\n",omp_get_num_threads());
//        }
        Hy(mm) = Chyh(mm) * Hy(mm) + 
        Chye(mm) * (Ez(mm + 1) - Ez(mm));
    }
    
    return;
}

// update E field
void updateE3(Grid *g){
    int mm;
    
    #pragma omp parallel for
    for (mm = 1; mm < SizeX; mm++) {
//        if (mm == 0 && Time == 1) {//check to see if omp is working
//                    printf("threads actuall: %d\n",omp_get_num_threads());
//        }
        Ez(mm) = Ceze(mm) * Ez(mm) + 
        Cezh(mm) * (Hy(mm) - Hy(mm - 1));
    }
    
    return;
}