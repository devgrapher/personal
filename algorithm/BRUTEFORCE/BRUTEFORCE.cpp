// BRUTEFORCE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
    int testCase = 0;
    std::cin >> testCase;
    for (int i = 0; i < testCase; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        long long sum = 1;
        
        // 1부터 a까지
        for (int j = 0; j < a; ++j)
        {
            sum = (sum * c) % 1000000007;
        }

        // a부터 b까지
        long long total = sum;
        for (int j = 0; j < b - a; ++j)
        {
            sum = (sum * c) % 1000000007;
            total = (sum + total) % 1000000007;
        }
        std::cout << total << std::endl;
    }
    return 0;
}
/*
#include <stdio.h>
#include <string.h>
 
typedef long long long64;
 
long64 mypow(long64 base, long64 limit, long64 max)
{
    if (limit==1)
        return base;
    else if (limit==0)
        return 1;
 
    long64 exp = 1, Sn;
    long64 mod = base;
 
    while(exp*2 <= limit) {
        mod=(((mod % max)*(mod % max)) % max);
        exp *= 2;
    }
     
    Sn = (mod * mypow(base,limit-exp,max))%max;
    return Sn;
}
 
long64 foo(long64 base, long64 exp, long64 max)
{
    if (exp <= 1)
        return 1;
 
    long64 mod1, mod2, Sn;
 
    if (exp % 2 == 0) 
    {
        mod1 = foo(base,exp/2,max);
        mod2 = (1+mypow(base,exp/2,max))%max;
 
        Sn = (mod1*mod2)%max;
    }
    else
    {
        mod1 = foo(base,exp-1,max);
        mod2 = mypow(base,exp-1,max);
         
        Sn = (mod1+mod2)%max;
    }
 
    return Sn;
}
 
int main()
{
    int T;
 
    scanf("%d", &T);
 
    while (T--)
    {
        int A, B, N;
 
        scanf("%d %d %d", &A, &B, &N);
 
        long64 mod1, mod2, Sn = 0;
        long64 max = 1000000007;
 
        if ( N == 1 )
            Sn = B-A+1;
        else
        {
            int n;
 
            n = B-A+1;
 
            mod1 = mypow(N, A, max);
            mod2 = foo(N, n, max);
            Sn = (mod1*mod2)%max;
        }
 
        printf("%lu\n", Sn);
    }
 
    return 0;
}
[출처] [AOJ 문제] Brute-Force Attack|작성자 열혈연구원
http://blog.naver.com/PostView.nhn?blogId=57gate&logNo=60118425477
*/