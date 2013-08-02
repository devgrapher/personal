// koi_color.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// http://211.228.163.31/30stair/color/color.php?pname=color&stair=20

#include "stdafx.h"
#include <iostream>


int N = 0;
int ar[129][129] = {0,};
int dp[129][129] = {0,};

int red = 0;
int white = 0;

void Process(int h, int w, int n)
{
	// 모두 같은색인지 판정
	int t = dp[h+n-1][w+n-1] - dp[h+n-1][w-1] - dp[h-1][w+n-1] + dp[h-1][w-1];
	if (t == (n * n))
	{
		++red;
		return;
	}
	else if (t == 0)
	{
		++white;
		return;
	}

	int dn = n / 2;
	Process(h, w, dn);
	Process(h + dn, w, dn);
	Process(h, w + dn, dn);
	Process(h + dn, w + dn, dn);
}

int main()
{
	std::cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			std::cin >> ar[i][j];
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + ar[i][j];
		}
	}

	Process(1, 1, N);

	std::cout<< white << std::endl;
	std::cout<< red << std::endl;
}
