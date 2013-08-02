// POJ2386_LakeCounting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>

bool table[100][100] = {0,};
int DIR[8][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};

void DFS(int i, int j)
{
	table[i][j] = false; // 현재 장소 치환
	for (int k = 0; k < 8; ++k)
	{
		int x = i + DIR[k][0];
		int y = j + DIR[k][1];
		if (table[x][y])
		{
			DFS(x, y);
		}
	}
}

int Process(int N, int M)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (table[i][j])
			{
				DFS(i, j);
				++count;
			}
		}
	}
	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int N,M = 0;
	std::wcin >> N >> M;

	std::wstring line; 
	std::getline(std::wcin, line); // 라인하나 무시

	for (int i = 0; i < N; ++i)
	{
		std::getline(std::wcin, line);

		if (line.length() < M)
		{
			continue;
		}
		for (int j = 0; j < M; ++j)
		{
			if (line[j] == L'W')
			{
				table[i+1][j+1] = true;
			}
			else
			{
				table[i+1][j+1] = false;
			}
		}
	}

	std::wcout << Process(N, M) << std::endl;

	return 0;
}

