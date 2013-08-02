// Knapsack.cpp : Defines the entry point for the console application.
//

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

	for (int i = N-1; i >=0; --i)// 물건을 N-1개에서 하나씩 골라간다(줄여간다)
	{
		for (int j = 0; j <= W; ++j)// 총 무게가 j일때 가격이 얼만지를 구해간다. 그래서 최종 무게가 W일때 얼만지가 나온다.(부분문제로 쪼갯음)
		{
			if (j < input[i][0])
			{
				dyn[i][j] = dyn[i+1][j];
			}
			else
			{
				dyn[i][j] = std::max(dyn[i+1][j] , dyn[i+1][j-input[i][0]] + input[i][1]);
			}
		}
	}

	std::wcout << dyn[0][W] << std::endl;




	return 0;
}

