// LongestIncreasingSubsequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int arr[1000] = {0,};
int dyn[1000] = {0,};

int LIS(int N)
{
	for (int i = 1; i <= N; ++i)
	{
		dyn[i] = 1;
		for (int j = 1; j <= i; ++j)
		{
			if (arr[j] < arr[i])
			{
				dyn[i] = std::max(dyn[i], dyn[j] + 1);
			}
		}
	}

	return dyn[N];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int caseCnt = 0;
	std::wcin >> caseCnt;

	for (int i = 0; i < caseCnt; ++i)
	{
		int N = 0;
		std::wcin >> N;

		for (int j = 1; j <= N; ++j)
		{
			std::wcin >> arr[j];
		}

		std::wcout << LIS(N);
	}

	return 0;
}

