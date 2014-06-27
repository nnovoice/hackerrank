/*
 * utopia.cpp
 *
 *  Created on: Jun 27, 2014
 *      Author: Raghavendran_N
 *      problem link: https://www.hackerrank.com/challenges/utopian-tree
 */
#include <stdio.h>

int GetTreeHeight(int nSeasons)
{

}

int main()
{
	int nCases = 0;
	int nSeasons = 0;
	int nTreeHeight = 0;

	scanf("%d", &nCases);


	for (int caseNum = 0; caseNum < nCases; ++caseNum) {
		scanf ("%d", &nSeasons);
		nTreeHeight = GetTreeHeight(nSeasons);
		printf("%d\n", nTreeHeight);
	}

	return 0;
}



