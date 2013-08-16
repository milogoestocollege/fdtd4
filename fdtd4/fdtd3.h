//
//  fdtd3.h
//  fdtd3
//
//  Created by CLP on 5/24/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef _FDTD3_h
#define _FDTD3_h

#include <stdio.h>
#include <stdlib.h>

struct Grid{
    double *ez, *ceze, *cezh;
    double *hy, *chyh, *chye;
    int sizeX;
    int time, maxTime;
    double cdtds;
};

typedef struct Grid Grid;

#define Hy(mm) g->hy[mm]
#define Chyh(mm) g->chyh[mm]
#define Chye(mm) g->chye[mm]

#define Ez(mm) g->ez[mm]
#define Ceze(mm) g->ceze[mm]
#define Cezh(mm) g->cezh[mm]

#define SizeX g->sizeX
#define Time g->time
#define MaxTime g->maxTime
#define Cdtds g->cdtds

/*memory allocation macro */

#define ALLOC_1D(PNTR, NUM, TYPE)                       \
    PNTR = (TYPE *)calloc(NUM, sizeof(TYPE));            \
    if(!PNTR){                                          \
        perror("ALLOC_1D");                             \
        fprintf(stderr,                                 \
            "Allocation failed for," #PNTR ". Terminating ...\n");\
        exit(-1);                                       \
    }

/*fucntion prototypes*/
void abcInit(Grid *g);
void abc(Grid *g);

void gridInit3(Grid *g);

void snapshotInit(Grid *g);
void snapshot(Grid *g);

void tfsfInit(Grid *g);
void tfsfUpdate(Grid *g);

void updateE3(Grid *g);
void updateH3(Grid *g);


#endif
