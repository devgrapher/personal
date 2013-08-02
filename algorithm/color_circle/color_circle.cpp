// color_circle.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

int N = 0;
int K = 0;

long long P(long long p)
{
	long long sum = 1;
	for (long long i = p; i > 0; --i)
	{
		sum = (sum * i) % 1000000003;
	}
	return sum;
}

long long C(long long n, long long k)
{
	if (k == 0)
	{
		return 1;
	}

	long long a = P(n);
	long long b = (P(k) * P(n - k)) % (long long)1000000003;
	long long c = a / b;
	return c;
}


int main()
{
	std::cin >> N;
	std::cin >> K;
	
	std::cout << C(N-K-1, K-1) + C(N-K, K);
}
