//
//  Global.hpp
//  mes
//
//  Created by Filip Zar�bi�ski on 05.12.2017.
//  Copyright � 2017 Filip Zar�bi�ski. All rights reserved.
//

#ifndef Global_hpp
#define Global_hpp

#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

class Global {
private:
	int nh, ne;
	float *s, *k, a, q, *L, To;

public:
	Global(string);

	// Getters
	int getNH(void);
	int getNE(void);
	float getS(int);
	float getK(int);
	float getA(void);
	float getQ(void);
	float getL(int);
	float getTo(void);
};

#endif /* Global_hpp */
