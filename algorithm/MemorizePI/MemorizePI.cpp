// MemorizePI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <algorithm>

const int SCORE[5] = {1, 2, 4, 5, 10};
const int MAX_SCORE = 10;

int Process(const std::wstring& str)
{
	int table[5][10001] = {0,};
	for (int i = 0; i < 4; ++i)
	{
		std::fill(table[i], table[i] + 10001, MAX_SCORE);
	}
	std::fill(table[4], table[4] + 10001, MAX_SCORE);
		
	for (int i = 2; i < str.size(); ++i)
	{
		int j = -1;
		if (str[i-2] == str[i-1] && str[i-1] == str[i])
		{
			j = 0;
		}

		if (str[i-2] - str[i-1] == str[i-1] - str[i] &&
			abs(str[i-1] - str[i]) == 1)
		{
			j = 1;
		}

		if (str[i-2] == str[i] && str[i-1] != str[i])
		{
			j = 2;
		}

		if (str[i-2] - str[i-1] == str[i-1] - str[i]	 &&
			abs(str[i-1] - str[i]) > 1)
		{
			j = 3;
		}

		if (j != -1)
		{
			table[j][i-2] = SCORE[j];
			table[j][i-1] = SCORE[j];
			table[j][i] = SCORE[j];
		}
	}


	// 다이나믹 첫줄 초기화
	int dyn[5][10001] = {0,};
	std::copy(table[0], table[0] + str.size(), dyn[0]);

	// 다이나믹 테이블 구성
	for (int i = 1; i < 5; ++i)
	{
		for (int j = 0; j < str.size(); ++j)
		{
			dyn[i][j] = std::min(table[i][j], dyn[i-1][j]);
		}
	}

	// 다이나믹 마지막줄이 암기 점수의 배열. 점수 계산
	int order[10001] = {0,};
	std::copy(dyn[4], dyn[4] + str.size(), order);
	int sum = 0;
	int cnt = 1;
	int n = order[0];
	for (int i = 1; i < str.size(); ++i)
	{
		if (cnt % 5 == 0 ||
			order[i] != order[i-1])
		{
			if (cnt < 3)
			{
				n = 10;
			}
			else
			{
				if (cnt >= 5)
				{
					cnt++;
				}
				if (order[i] != order[i-1])
				{
					cnt = 1;
				}
				
				sum += n;
				n = order[i];
			}
		}
		else
		{
			++cnt;
		}
	}
	n = order[str.size()-1];
	sum += n;

	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int caseCnt = 0;
	std::wcin >> caseCnt;
	std::cin.ignore(256, '\n');

	for (int c = 0; c < caseCnt; ++c)
	{
		std::wstring buf;
		std::getline(std::wcin, buf);

		std::wcout << Process(buf) << std::endl;		
	}


	return 0;
}

