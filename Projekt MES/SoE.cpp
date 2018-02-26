//
//  SoE.cpp
//  mes
//
//  Created by Filip Zarêbiñski on 05.12.2017.
//  Copyright © 2017 Filip Zarêbiñski. All rights reserved.
//

#include "stdafx.h"
#include "SoE.h"

SoE::SoE(string filepath) {
	// Initialize variables
	this->grid = new Grid(filepath);
	Global global = grid->getGlobal();
	float c;

	this->GH = new float*[grid->getNH()];
	this->GP = new float[grid->getNH()];
	this->GT = new float[grid->getNH()];

	for (int i = 0; i<grid->getNH(); i++) {
		this->GH[i] = new float[grid->getNH()];
		this->GP[i] = 0;

		for (int j = 0; j<grid->getNH(); j++) {
			this->GH[i][j] = 0;
		}
	};

	for (int i = 0; i<grid->getNH(); i++) {
		this->GP[i] = 0;
	}

	// Go through elements
	for (int i = 0; i<grid->getNE(); i++) {
		c = (grid->getElement(i).S*grid->getElement(i).K) / (grid->getNode(i, 1).x - grid->getNode(i, 0).x);
		grid->setElementH(i, 0, 0, c);
		grid->setElementH(i, 1, 1, c);
		grid->setElementH(i, 0, 1, -c);
		grid->setElementH(i, 1, 0, -c);

		if (grid->getNode(i, 0).status == 2) {
			grid->setElementH(i, 0, 0, grid->getElement(i).H[0][0] + (global.getA()*grid->getElement(i).S));
		}
		if (grid->getNode(i, 1).status == 2) {
			grid->setElementH(i, 1, 1, grid->getElement(i).H[1][1] + (global.getA()*grid->getElement(i).S));
		}

		if (grid->getNode(i, 0).status == 1) {
			grid->setElementP(i, 0, global.getQ()*grid->getElement(i).S);
		}
		if (grid->getNode(i, 1).status == 1) {
			grid->setElementP(i, 1, global.getQ()*grid->getElement(i).S);
		}
		if (grid->getNode(i, 0).status == 2) {
			grid->setElementP(i, 0, -global.getA()*(grid->getElement(i).S*global.getTo()));
		}
		if (grid->getNode(i, 1).status == 2) {
			grid->setElementP(i, 1, -global.getA()*(grid->getElement(i).S*global.getTo()));
		}
	};

	// Generate Global Grid
	int ID1, ID2;

	for (int i = 0; i<grid->getNE(); i++) {
		ID1 = grid->getElement(i).ID[0];
		ID2 = grid->getElement(i).ID[1];

		this->GH[ID1][ID1] += grid->getElement(i).H[0][0];
		this->GH[ID1][ID2] += grid->getElement(i).H[0][1];
		this->GH[ID2][ID1] += grid->getElement(i).H[1][0];
		this->GH[ID2][ID2] += grid->getElement(i).H[1][1];

		this->GP[ID1] += grid->getElement(i).P[0];
		this->GP[ID2] += grid->getElement(i).P[1];
	}

	this->GT = MESMath::convertToOpposite(MESMath::gauss(this->GH, this->GP, grid->getNH()), grid->getNH());
};

SoE::~SoE(void) {
	delete this->GH;
	delete this->GP;
	delete this->GT;
	delete this->grid;
}

int SoE::getNH(void) {
	return grid->getNH();
}

float** SoE::getGH(void) {
	return this->GH;
}

float* SoE::getGP(void) {
	return this->GP;
}

float* SoE::getGT(void) {
	return this->GT;
}
