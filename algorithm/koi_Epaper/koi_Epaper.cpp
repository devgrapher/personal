// koi_Epaper.cpp : Defines the entry point for the console application.
// http://211.228.163.31/pool/koi_Epaper/koi_Epaper.php?pname=koi_Epaper

#include "stdafx.h"
#include <iostream>


int table[100][100] = {0,}; // 도화지
const int PaperSize = 10;

void InsertPaper(int x, int y)
{
	for (int i = 0; i < PaperSize; ++i)
	{
		for (int j = 0; j < PaperSize; ++j)
		{
			table[x + i][y + j] = 1;
		}
	}
}

int Process()
{
	int cnt = 0;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (table[i][j])
			{
				++cnt;
			}
		}
	}
	return cnt;
}

int main()
{
	int cnt = 0; // 색종이수
	std::cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		int x = 0;
		int y = 0;
		std::cin >> x >> y;
		InsertPaper(x, y);
	}
	std::cout << Process() << std::endl;

	return 0;
}

