// UVA357_CoinChange.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	int coins[5] = {1, 5, 10 ,25, 50};
	int dyn[30001] = {1,0,};

	// 각 동전으로 조합가능한 수를 만들어 간다.
	for(int i = 0; i < _countof(coins); ++i)
	{
		for(int j = 1; j <= 30000; ++j)
		{
			if (coins[i] <= j) // 동전금액보다 크거나 같으면
			{
				dyn[j] += dyn[j - coins[i]]; // 현재 합계에서 동전금액을 뺀위치의 조합 수를 현재 조합수에 더한다.
			}
		}
	}

	while(!std::cin.eof() && !std::cin.fail())
	{
		int sum = 0;
		std::cin >> sum;
		std::cout<< dyn[sum] << std::endl;
	}

	return 0;
}

