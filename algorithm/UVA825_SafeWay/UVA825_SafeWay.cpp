// UVA825_SafeWay.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>


bool table[101][101] = {0,};
int dyn[101][101] = {0,};

int _tmain(int argc, _TCHAR* argv[])
{
	int testCase = 0;
	std::cin >> testCase;

	while (!std::cin.fail())
	{
		std::cin.ignore(256, '\n');

		int W = 0;
		int N = 0;
		std::cin >> W >> N;
		
		if (std::cin.fail()) { break; }

		int w = 0;
		std::string line;
		for (int i = 1; i <= W; ++i)
		{
			std::getline(std::cin, line);
			std::istringstream in(line);

			int t1 = 0;
			int t2 = 0;
			in >> t1;
			while (in >> t2)
			{
				table[t1][t2] = true;
			}
		}

		/* 처리*/

		// 첫번째 줄 선처리
		if (!table[1][1])
		{
			dyn[1][1] = 1;
		}
		for (int i = 2; i <= N; ++i)
		{
			if (!table[1][i])
			{
				dyn[1][i] = dyn[1][i-1]; // 위험한 교차로가 아니면 왼쪽값을 입력한다.
			}
		}

		for (int i = 2; i <= W; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (table[i][j])
				{
					dyn[i][j] = 0;
				}
				else
				{
					dyn[i][j] = dyn[i-1][j] + dyn[i][j-1];
				}
			}
		}

		int result = dyn[W][N];

		std::cout << result << std::endl << std::endl;
	}
	

	return 0;
}

