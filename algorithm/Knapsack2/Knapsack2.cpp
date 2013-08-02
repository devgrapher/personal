// Knapsack2.cpp : Defines the entry point for the console application.
//

/*
	갯수에 제한 없는 배낭문제
	무게와 가격이 각각 w, v인 n개의 물건이 있습니다. 이 물건들로부터 무게의 총합이 W를 초과하지 않도록
	선택했을 때의 가격 총합의 최대치를 구하세요. 단 같은 종류의 물건을 몇 개라도 고르는 것이 가능합니다.

	입력
	n = 3
	W = 7
	(w,v) = {(3,4),(4,5),(2,3)}
	출력
	10(0번 1개, 2번 2개를 고른다)
*/


#include "stdafx.h"
#include <iostream>

int dyn[101][10001] = {0,};// 남은 물건 갯수 | 현재까지 물건을 합쳤을때 무게
int input[101][2] = {0,};

int _tmain(int argc, _TCHAR* argv[])
{
	int N, W = 0;
	std::wcin >> N >> W;
	for (int i = 1; i <= N; ++i)
	{
		std::wcin >> input[i][0] >> input[i][1];
	}
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			for (int k = 1; k <= N; ++k)
			{
				int m = std::max(dyn[i-1][j-1] + input[k][1], input[k][1]);
				if (j > m)
				{
					dyn[i][j] = m;
				}
				else
				{
					dyn[i][j] = dyn[i-1][j-1];
				}
			}
		}
	}

	std::cout << dyn[N][W] << std::endl;

	return 0;
}

