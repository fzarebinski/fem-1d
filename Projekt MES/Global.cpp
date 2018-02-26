//
//  Global.cpp
//  mes
//
//  Created by Filip Zarêbiñski on 05.12.2017.
//  Copyright © 2017 Filip Zarêbiñski. All rights reserved.
//

#include "stdafx.h"
#include "Global.h"

Global::Global(string filename) {
	fstream file;
	file.open(filename);
	string data;
	/*
	FILE STRUCTURE:

	NH Ta q ALPHA
	NE L K S
	NE L K S
	NE L K S
	...
	*/

	if (file.is_open()) {
		getline(file, data, ' ');
		this->nh = stoi(data);
		this->ne = this->nh - 1;

		this->k = new float[this->nh];
		this->s = new float[this->nh];
		this->L = new float[this->nh];

		getline(file, data, ' ');
		this->To = stof(data);

		getline(file, data, ' ');
		this->q = stof(data);

		getline(file, data);
		this->a = stof(data);

		//===
		int i = 0;
		while (i < this->ne) {
			getline(file, data, ' ');
			int neLocal = stoi(data);

			getline(file, data, ' ');
			this->L[i] = stof(data) / neLocal;

			getline(file, data, ' ');
			this->k[i] = stof(data);
			
			getline(file, data);
			this->s[i] = stof(data);

			int kon = i + neLocal;

			for (int j = (i+1); (j < kon && j < this->ne); j++) {
				this->k[j] = this->k[i];
				this->s[j] = this->s[i];
				this->L[j] = this->L[i];
			}

			i = kon;
		}
		//===
	}
}

int Global::getNH(void) {
	return this->nh;
};

int Global::getNE(void) {
	return this->ne;
};

float Global::getS(int i) {
	return this->s[i];
};

float Global::getK(int i) {
	return this->k[i];
};

float Global::getA(void) {
	return this->a;
};

float Global::getQ(void) {
	return this->q;
};

float Global::getL(int i) {
	return this->L[i];
};

float Global::getTo(void) {
	return this->To;
};
