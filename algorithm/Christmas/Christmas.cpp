// Christmas.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// http://www.algospot.com/judge/problem/read/CHRISTMAS

#include "stdafx.h"
#include <iostream>

int main()
{
	int T = 0;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int N = 0; // 인형상자의 갯수
		int K = 0; // 어린이 수
		std::cin >> N >> K;

		int child[100001] = {0,};
		for (int n = 1; n <= N; ++n)
		{
			std::cin >> child[n];
		}

		int dyn[100001] = {0,};
		for (int i = 1; i <= N; ++i)
		{
			
		}
	}


	return 0;
}
/*
#include <iostream> 
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std; 

int T, N, K;
int D[100001];
int PS[100001];

long long getResult1()
{
     vector<int> C(K, 0);
     C[0] = 1;
     for(int i = 1;i <= N; i++){
          PS[i] = (D[i]+PS[i-1])%K;
          C[PS[i]]++;
     }
     long long result = 0;
     for(int i = 0; i < K; i++)
     {
          if(C[i] >= 2){
               result += C[i]*(C[i]-1LL)/2;
               result %= 20091101;
          }
     }
     return result;
}

int getResult2()
{
     vector<int> result(N+1, 0);
     vector<int> prev(K, -1);
     for(int i = 0; i <= N; ++i){
          result[i] = i?result[i-1]:0;
          if(prev[PS[i]] != -1) result[i] = max(result[i], result[prev[PS[i]]]+1);
          prev[PS[i]] = i;
     }
     return result[N];
}

int main()
{
     scanf("%d", &T);
     while(T --> 0)
     {
          scanf("%d %d", &N, &K);
          for(int i = 1;i <= N; i++){scanf("%d", D+i);}

          long long result1 = getResult1();
          int result2 = getResult2();
          printf("%lld %d\n", result1, result2);

     }
     return 0;
}
*/