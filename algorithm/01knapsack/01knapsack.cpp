// 01knapsack
// http://211.228.163.31/30stair/01knapsack/01knapsack.php?pname=01knapsack

#include "stdafx.h"
#include <iostream>
#include <algorithm>

int N = 0; // 가방 무게
int M = 0; // 보석 갯수
int in[101][2] = {0,}; // 무게, 가치
int dp[101][10001] = {0,};

int Process()
{
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (j < in[i][0]) // i번째보석이 j사이즈(무게)의 가방에 들어가는지 확인
			{
				dp[i][j] = dp[i-1][j];

			}
			else
			{
				dp[i][j] = std::max(dp[i-1][j], in[i][1] + dp[i-1][j-in[i][0]]);
				/*
				std::max({1}, {2-1} + {2-2});
				{1}은 현재 i번째 보석을 선택안했을때의 최대 가치
				{2}는 현재 i번재 보석을 선택했을때의 최대 가치
				둘중 가장 큰것을 dp[i][j]에 저장한다.
				(i번째 보석까지 선택했을때 j가방 무게에서의 최대 가치)
				
				{1} : 이전 보석까지 선택했을때 현재무게인 j무게에서 최대가치.
				{2-1} : 현재 보석의 가치
				{2-2} : 현재 보석의 무게in[i][0]에 현재 가방무게j를 뺐을때 남은 무게에서의 최대가치
						즉 현재 무게 j에서 방금선택한 보석 무게를 빼면 k의 무게가 남는데
						그 무게로 담을수 있는 최대가치를 i-1(이전보석까지선택한케이스)에서 구해온것이다.
				{2-1}에 {2-2}를 더하는 이유는 바로 현재 보석을 선택하고도 남은 가방무게에 대해 
				다른 보석을 더 담기 위함이다. 이때 더 담을 수 있는 무게는 이미 이전에 계산되었으므로 그것을 참고한다.
				*/
			}
		}
	}
	return dp[M][N];
}

int main()
{
	std::cin >> N >> M;
	for (int i = 1; i <= M; ++i)
	{
		std::cin >> in[i][0] >> in[i][1];
	}

	std::cout << Process();
}
