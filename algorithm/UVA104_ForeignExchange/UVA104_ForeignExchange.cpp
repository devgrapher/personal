// UVA104_ForeignExchange.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


double dyn[21][21][21] = {0,};
double input[21][21] = {0,};


int _tmain(int argc, _TCHAR* argv[])
{
	while(!std::cin.fail())
	{
		int N = 0;
		std::cin >> N;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (i == j)
				{
					// 자신은 1로 세팅
					input[i][j] = 1.0;
				}
				else
				{
					std::cin >> input[i][j];
				}
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			std::copy(input[i], input[i] + N + 1, dyn[0][i]);
		}


	}

	return 0;
}

