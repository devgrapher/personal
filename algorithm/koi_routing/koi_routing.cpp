// koi_routing.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// http://211.228.163.31/pool/koi_routing/koi_routing.php?pname=koi_routing

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

int N = 0;
int table[1001][1001] = {0,};
int dp[3][1002][1002] = {0,};// 3은 위, 왼쪽, 오른쪽 에 해당하는 각각의 테이블을 만들기 위함
const int MAXINT = 1000000;

int Solve()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			dp[0][i][j] = std::max(dp[2][i-1][j], std::max(dp[0][i-1][j], dp[1][i-1][j])) + table[i][j]; // 위쪽 에서 내려온 경우 처리
			dp[1][i][j] = std::max(dp[0][i][j-1], dp[1][i][j-1]) + table[i][j]; // 왼쪽에서 온경우 처리(이경우 "왼쪽위", "왼쪽왼쪽"에서 온경우만 계산
		}

		if (i > 1)
		{
			for (int j = N; j > 0; --j)
			{
				dp[2][i][j] = std::max(dp[0][i][j+1], dp[2][i][j+1]) + table[i][j]; // 오른쪽에서 온경우 처리(이경우 "오른쪽위", "오른쪽오른쪽"에서 온경우만 계산
			}
		}
	}

	return std::max(dp[2][N][N], std::max(dp[0][N][N], dp[1][N][N]));
}
/*
int Solve()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + table[i][j];
		}
		if (i >= 2)
		{
			int dp2[1002] = {0,};
			for (int j = N; j > 0; --j)
			{
				dp2[j] = std::max(dp[i-1][j], dp2[j+1]) + table[i][j];
				dp[i][j] = std::max(dp[i][j], dp2[j]);
			}
		}
	}

	return dp[N][N];
}
*/

int main()
{	
	std::cin >> N;
	std::cin.ignore(256,'\n');
	for (int i = 1; i <= N; ++i)
	{
		std::string line;
		std::getline(std::cin, line);
		std::istringstream in(line);

		for (int j = 1; j <= N; ++j)
		{
			in >> table[i][j];
		}
	}

	std::cout << Solve() << std::endl;

	return 0;
}
