// Anagram.cpp : Defines the entry point for the console application.
// http://www.algospot.com/judge/problem/read/ANAGRAM

#include "stdafx.h"
#include <stdio.h>
#include <algorithm>

char n[101] = {0,};
char k[101] = {0,};

bool Process()
{
	if (strcmp(n, k) == 0)
	{
		return false;
	}
	std::sort(n, n + strlen(n));
	std::sort(k, k + strlen(k));

	return strcmp(n, k) == 0;
}

int main()
{
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
	{
		std::cin >> n >> k;
		std::cout << (Process() ? "Yes" : "No.") << std::endl;
	}

	return 0;
}

