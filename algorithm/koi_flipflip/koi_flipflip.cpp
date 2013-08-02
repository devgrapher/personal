// koi_flipflip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int table[10000] = {0,};
int a[10000] = {0,};
int m = 100000;

void flip(int i, int j)
{
	int m = (j - i) / 2;
	for (int k = 0; k <= m; ++k)
	{
		std::swap(table[i + k], table[j - k]);
	}
}

int Process(int N, int c)
{
	int s = -1;
	int e = -1;
	int sum = 0;
	for (int i = 2; i < N; ++i)
	{
		if (table[i] - table[i-1] !=	 1)
		{
			if (s == -1)
			{
				s = i;
			}
			else
			{
				e = i -1;
			}
			
			if (e > s)
			{
				flip(s, e);
				m = std::min(Process(N, c + 1), m);
				flip(s, e); // 다시 되돌린다.
				s = e;
				s = -1;
			}
		}
		++sum;
	}

	if (sum == N - 2)
	{
		return c;
	}
	else
	{
		return 100000;
	}
}

int main()
{
	int N = 0;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> table[i];
		if (i > 0)
		{
			a[i] = table[i] - table[i-1];
		}
	}

	Process(N, 1);


	return 0;
}

