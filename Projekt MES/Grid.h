//
//  Grid.hpp
//  mes
//
//  Created by Filip Zarêbiñski on 05.12.2017.
//  Copyright © 2017 Filip Zarêbiñski. All rights reserved.
//

#ifndef Grid_hpp
#define Grid_hpp

#include <stdio.h>
#include "Node.h"
#include "Element.h"
#include "Global.h"

class Grid {
private:
	int nh, ne;
	Node* N;
	Element* E;
	Global* global;

public:
	Grid(string);
	~Grid(void);
	int getNE(void);
	int getNH(void);
	Global getGlobal(void);
	Node getNode(int);
	Node getNode(int, int);
	Element getElement(int);
	bool setElementH(int, short int, short int, float);
	bool setElementP(int, short int, float);
};

#endif /* Grid_hpp */
