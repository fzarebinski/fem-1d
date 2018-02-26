//
//  MESMath.cpp
//  mes
//
//  Created by Filip Zarêbiñski on 06.12.2017.
//  Copyright © 2017 Filip Zarêbiñski. All rights reserved.
//

#include "stdafx.h"
#include "MESMath.h"

float* MESMath::gauss(float** tab, float* values, int n) {
	float** mergedTab = new float *[n];

	// Compare tabs
	for (int i = 0; i<n; i++) {
		mergedTab[i] = new float[(n + 1)];

		for (int j = 0; j<n; j++) {
			mergedTab[i][j] = tab[i][j];
		}

		mergedTab[i][n] = values[i];
	}

	return MESMath::gauss(mergedTab, n);
}

float* MESMath::gauss(float** tab, int n) {
	float* gauss = new float[n];

	if (n>0) {
		// Count last unknown variable
		for (int i = 0; i<(n - 1); i++) {
			if (tab[i][i] != 0) {
				for (int j = (i + 1); j<n; j++) {
					double w = (tab[j][i] / tab[i][i]);

					for (int k = 0; k<(n + 1); k++) {
						tab[j][k] -= (tab[i][k] * w);
					}
				}
			}
			else {
				for (int j = (i + 1); j<n; j++) {
					if (tab[j][i] != 0) {
						float *tmpTab = tab[j];
						tab[j] = tab[i];
						tab[i] = tmpTab;
						i--;
					}
				}
			}
		}

		tab[(n - 1)][n] /= tab[(n - 1)][(n - 1)];
		tab[(n - 1)][(n - 1)] = 1;

		// Base on last known value count other variables
		for (int i = (n - 1); i>0; i--) {
			if (tab[i][i] != 0) {
				for (int j = (i - 1); j >= 0; j--) {
					float w = (tab[j][i] / tab[i][i]);

					for (int k = 0; k<(n + 1); k++) {
						tab[j][k] -= (tab[i][k] * w);
					}
				}
			}
			else {
				// If it's zero swap rows
				for (int j = (i + 1); j<n; j++) {
					if (tab[j][i] != 0) {
						float *tmpTab = tab[j];
						tab[j] = tab[i];
						tab[i] = tmpTab;
						i--;
						break;
					}
				}
			}
		}

		// Compare other values to 1
		for (int i = 0; i<(n - 1); i++) {
			tab[i][n] /= tab[i][i];
			tab[i][i] = 1;
			gauss[i] = tab[i][n];
		}

		gauss[(n - 1)] = tab[(n - 1)][n];
	};

	return gauss;
};

float* MESMath::convertToOpposite(float* tab, int n) {
	for (int i = 0; i<n; i++) {
		tab[i] = -tab[i];
	}
	return tab;
}
