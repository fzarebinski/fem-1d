//
//  MESMath.hpp
//  mes
//
//  Created by Filip Zar�bi�ski on 06.12.2017.
//  Copyright � 2017 Filip Zar�bi�ski. All rights reserved.
//

#ifndef MESMath_hpp
#define MESMath_hpp

#include <stdio.h>

class MESMath {
public:
	static float* gauss(float**, int);
	static float* gauss(float**, float*, int);
	static float* convertToOpposite(float*, int);

};

#endif /* MESMath_hpp */
