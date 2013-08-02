// NighitsTourProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int table[1000][1000] = {0,};
int N, M = 0;

void Process()
{
	const int baseTable[5][5] = {
		{4,1,2,1,4},
		{1,2,3,2,1},
		{2,3,0,3,2},
		{1,2,3,2,1},
		{4,1,2,1,4},
	};

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int index = i * N + j; // ÁÂÇ¥ ÀÎµ¦½º
			
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int caseCnt = 0;
	std::cin >> caseCnt;
	
	std::cin >> N >> M;
	Process();

	for (int i = 0 ; i < caseCnt; ++i)
	{
			
	}

	return 0;
}

