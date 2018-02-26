//
//  SoE.hpp
//  mes
//
//  Created by Filip Zarêbiñski on 05.12.2017.
//  Copyright © 2017 Filip Zarêbiñski. All rights reserved.
//

#ifndef SoE_hpp
#define SoE_hpp

#include <stdio.h>
#include <iostream>
#include "Grid.h"
#include "MESMath.h"

class SoE {
private:
    float** GH;
    float* GP;
    float* GT;
	Grid* grid;

public:
    SoE(string);
    ~SoE(void);
    float** getGH(void);
    float* getGP(void);
    float* getGT(void);
	int getNH(void);
};

#endif /* SoE_hpp */
