// station.cpp : Defines the entry point for the console application.
// http://211.228.163.31/pool/station/station.php?pname=station

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

int N = 0;
std::vector<std::pair<int,int> > in;
const int MAXINT = 1000000;
int dp[10000] = {0,};
int MaxY[10000][10000] = {0,};

void InitMaxY(int i, int j) // i에서 j-1구간사이의 최대 Y값을 구한다.
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			if (j == 0)
			{
				MaxY[i][j] = in[0].second;
			}
			else
			{
				MaxY[i][j] = std::max(MaxY[i][j-1], in[j].second);
			}
		}
	}
}

int Cost(int i, int j)// i에서 j까지 하나의 기지국(정사각형)으로 묶을때 최소 비용.
{
	int x = in[i].first; // 시작지점 x 좌표
	int maxY = MaxY[i][j]; // i에서 j까지의 최대 Y값.
	return std::max(in[j].first - x, maxY); // 현재까지 최대 비용.(최대Y와 j까지 이동거리중 큰 값)
}

int Process()
{
	std::fill(dp, dp + 10000, MAXINT);

	dp[0] = in[0].second * 2; // 최우측 좌표의 Y 값을 가지고 시작.(어차피 거리는 0이므로 X는 고려 안함)
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			dp[i] = std::min(dp[i], dp[j] + Cost(j + 1, i));
		}
		// 처음부터 i까지 하나로 연결했을때의 비용도 추가로 비교한다.
		dp[i] = std::min(dp[i], Cost(0, i));
	}

	return dp[N-1];
}

int Pred(const std::pair<int, int>& l, const std::pair<int, int>& r)
{
	return l.first < r.first ? 1 : 0;
}

int main()
{
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		in.push_back(std::make_pair(x, abs(y) * 2)); // 미리 *2를 해둔다. 원래는 cost에서 할 값.
	}
	std::sort(in.begin(), in.end(), Pred);

	InitMaxY(0, N);

	std::cout << Process();

	return 0;
}

/*
int Cost(int i, int j)// i에서 j까지 하나의 기지국(정사각형)으로 묶을때 최소 비용.
{
	int s = in[i].first; // 시작지점 x 좌표
	int maxY = in[i].second;
	for (int k = i + 1; k <= j; ++k)
	{
		maxY = std::max(maxY, in[k].second); // 현재까지 최대Y값.
		
	}
	return std::max(in[j].first - s, maxY * 2); // 현재까지 최대 비용.(최대Y와 j까지 이동거리중 큰 값)

}
*/