// Expedition.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// 노란책 102p, 우선순위큐, POJ 2431

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <queue>

int N = 0; // 가솔린스탠드 갯수
int L = 0; // 총 이동할거리
int P = 0; // 출발시 가진 연료
int Pos[10000] = {0,}; // 가솔린스탠드 위치(이전위치에서의 거리)
int Qtt[10000] = {0,}; // 위치마다 충전가능한 양.


int Process()
{
	std::priority_queue<int> que;

	int fuel = P;
	int suppCount = 0; // 연료 충전 횟수
	for (int i = 0; i < N; ++i)
	{
		que.push(Qtt[i]);
		fuel -= Pos[i];// 이동했다는 뜻임.
		while (fuel < 0 && !que.empty()) 
		{
			fuel += que.top(); // 연료충전
			que.pop();
			suppCount++;
		}
		if (fuel < 0)
		{
			return -1;
		}
	}

	return suppCount;
}

int main()
{
	std::cin >> N >> L >> P;
	int lastP = 0;
	for (int i = 0; i < N; ++i)
	{
		int p = 0;
		std::cin >> p >> Qtt[i];
		Pos[i] =  p - lastP; // 이전위치에서의 거리를 입력
		lastP = p;
	}

	std::cout << Process();
}
