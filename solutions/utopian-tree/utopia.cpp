/*
 * utopia.cpp
 *
 *  Created on: Jun 27, 2014
 *      Author: Raghavendran_N
 *      problem link: https://www.hackerrank.com/challenges/utopian-tree
 */
#include <stdio.h>

const int MAXSEASONS = 61;

typedef unsigned int uint;

void PopulateTreeHeights(uint* treeHeights, size_t nElements)
{
	uint height = 0;
	for (size_t i = 0; i < nElements; ++i) {
		treeHeights[i] = ((i % 2) == 0) ? (height += 1) : (height *= 2);
		//printf("%u %u\n", i, treeHeights[i]);
	}
}

int main()
{
	int nCases = 0;
	uint nSeasons = 0;
	uint treeHeights[MAXSEASONS] = {0};

	PopulateTreeHeights(treeHeights, sizeof(treeHeights)/sizeof(int));

	scanf("%u", &nCases);

	for (int caseNum = 0; caseNum < nCases; ++caseNum) {
		scanf ("%u", &nSeasons);
		printf("%u\n", treeHeights[nSeasons]);
	}

	return 0;
}



