//
//  Grid.cpp
//  mes
//
//  Created by Filip Zarêbiñski on 05.12.2017.
//  Copyright © 2017 Filip Zarêbiñski. All rights reserved.
//

#include "stdafx.h"
#include "Grid.h"

Grid::Grid(string filepath) {
	this->global = new Global(filepath);
	this->nh = global->getNH();
	this->ne = global->getNE();
	this->N = new Node[this->nh];
	this->E = new Element[this->ne];

	float dx = 0;

	for (int i = 0; i<this->ne; i++) {
		this->E[i].ID[0] = i;
		this->E[i].ID[1] = (i + 1);

		this->E[i].K = global->getK(i);
		this->E[i].S = global->getS(i);

		for (int j = 0; j < 3; j++) {
			this->E[i].P[j] = 0;
		}
	}

	for (int i = 0; i<this->nh; i++) {
		this->N[i].x = dx;
		if(i != this->ne) {
			this->E[i].L = global->getL(i);
			dx += this->E[i].L;
		}

		if (!i) {
			this->N[i].status = 1;
		}
		else if (i == this->ne) { //optimization, there is using ne, because this is (nh-1), so this is index for last nh element
			this->N[i].status = 2;
		}
	}
}

Grid::~Grid(void) {
	delete this->N;
	delete this->E;
	delete this->global;
}

int Grid::getNE(void) {
	return this->ne;
}

int Grid::getNH(void) {
	return this->nh;
}

Global Grid::getGlobal(void) {
	return *(this->global);
};

Node Grid::getNode(int i) {
	if (i<this->nh) {
		return this->N[i];
	}
	return this->N[0];
}

Node Grid::getNode(int elementI, int idFromElement) {
	if (elementI<this->ne) {
		return this->N[this->E[elementI].ID[idFromElement]];
	}
	return this->N[0];
}

Element Grid::getElement(int i) {
	if (i<this->ne) {
		return this->E[i];
	}
	return this->E[0];
}

bool Grid::setElementH(int elementID, short int idH1, short int idH2, float value) {
	if (idH1<2 && idH1 >= 0 && idH2<2 && idH2 >= 0) {
		this->E[elementID].H[idH1][idH2] = value;
		return true;
	}
	return false;
}

bool Grid::setElementP(int elementID, short int idP, float value) {
	if (idP<2 && idP >= 0) {
		this->E[elementID].P[idP] = value;
		return true;
	}
	return false;
}
