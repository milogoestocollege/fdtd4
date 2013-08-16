//
//  abc.c
//  fdtd3
//
//  Created by CLP on 5/24/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "fdtd3.h"

void abcInit(Grid *g){
    
    return;
}

void abc(Grid *g){
    
    /* super simple abc for left edge */
    
    Ez(0) = Ez(1);
    return;
}