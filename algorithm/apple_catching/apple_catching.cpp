// apple_catching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int T = 0;
int W = 0;
int in[1000][2] = {0,};

int Process(int t, int w, int k)
{
	if (t == T)
	{
		return 0;
	}

	int a = 0;
	int b = 0;
	if (w < W)
	{
		a = Process(t + 1, w + 1, k == 0 ? 1 : 0) + in[t][k == 0 ? 1 : 0];
	}
	b = Process(t + 1, w, k) + in[t][k];
	return std::max(a, b);
}

int main()
{
	std::cin >> T >> W;
	for (int t = 0; t < T; ++t)
	{
		int c = 0;
		std::cin >> c;
		if (c == 1)
		{
			in[t][0] = 1;
		}
		else
		{
			in[t][1] = 1;
		}
	}

	std::cout << Process(0, 0, 0);

	return 0;
}

