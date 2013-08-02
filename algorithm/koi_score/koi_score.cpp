// koi_score.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>

int num[150] = {0,};
int N = 0;
int K = 0; // 목표점수
const int MAXINT = 2000000001;
std::set<int> numList; // 가능한 점수리스트

void Process(int score, int c, int i)
{
	if (i >= N) // 배열 범위 초과라면
	{
		if (score >= K)
		{
			numList.insert(score);
		}
		return;
	}

	Process(score + c + num[i], c + num[i], i + 1);
	Process(score, 0, i + 1);

	return;
}

int main()
{
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> num[i];
	}
	std::cin >> K;

	Process(0, 0, 0);

	int a = K;
	for (std::set<int>::iterator it = numList.begin(); it != numList.end(); ++it)
	{
		if (*it != a)
		{
			break;
		}
		++a;
	}
	std::cout << a;	

	return 0;
}

