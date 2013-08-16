//
//  snapshot.c
//  fdtd3
//
//  Created by CLP on 5/24/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "fdtd3.h"

static int temporalStride = 0, spatialStride, startTime, startNode, endNode, frame = 0;

static char basename[50];

void snapshotInit(Grid *g){
    
    printf("For the snapshots: \n");
    printf("    Duration of simulation is %d steps.\n", MaxTime);
    printf("    Enter start time and temporal stride: ");
    scanf("%d %d", &startTime, &temporalStride);
    printf("    Grid has %d total nodes (from 0 to %d.\n", SizeX, SizeX - 1);
    printf("    Enter first node, last node and spatial stride: ");
    scanf("%d %d %d", &startNode, &endNode, &spatialStride);
    printf("    Enter the base name: ");
    scanf("%s", basename);
          
    return;
}

void snapshot(Grid *g){
    int mm;
    char filename[100];
    FILE *snapshots;
    
    //take a snapshot at the right times
    if( Time >= startTime && (Time - startTime) % temporalStride == 0){
        sprintf(filename, "%s.%d",basename, frame++);
        
        snapshots = fopen(filename, "w");
        for (mm = startNode; mm <= endNode; mm+=spatialStride) {
            fprintf(snapshots, "%g\n", Ez(mm));
//            printf("%g\n",Ez(mm));
        }
        fclose(snapshots);//maybe this goes outside the for loop
    }
    
    return;
}

