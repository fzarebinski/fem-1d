//
//  main.cpp
//  mes
//
//  Created by Filip Zarębiński on 25.11.2017.
//  Copyright © 2017 Filip Zarębiński. All rights reserved.
//

#include "stdafx.h"
#include <iostream>
#include "SoE.h"

using namespace std;

int main(int argc, const char * argv[]) {
	// insert code here...
	SoE a("data.txt");

	float* G2 = a.getGT();
	
	cout << "Temperature in nodes\n======================================\n" << endl;
	for (int i = 0; i<a.getNH(); i++) {
		cout << "t" << (i+1) << ": " << G2[i] << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}
