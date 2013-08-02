// AvoidYourProfessor.cpp : Defines the entry point for the console application.
// http://www.algospot.com/judge/problem/read/AVOID
// 다익스트라 참고 : http://www.unf.edu/~wkloster/foundations/DijkstraApplet/DijkstraApplet.htm

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <queue>


void dijkstra(int (*a)[101], int n, int (*visit)[101])
{
	// a 는 거리값이 담긴 이차원 배열
	int w = 0;
	int start = 1;
	int di[101] = {0,}; // di 는 해당 노드까지의 최소값을 업데이트해 나갈 1차원 임시 배열
	for (int i = 1; i <= n; ++i)
	{
		di[i] = 10000; // 아직 아무것도 구해지지 않았으므로 최대값으로 세팅
	}
	int chk[101] = {0,}; // 최소 거리가 확정된 노드

	di[start] = 0;// 시작점은 거리 0으로 세팅한다. 그래야 break로 안빠져나갈거다.
	for(int i = 1; i <= n; i++)
	{
		int min = 10000;
		for(int j = 1; j <= n; j++)
		{
			if(min > di[j] && chk[j] == 0)
			{
				min=di[j];				// 현재까지 구한 점들의 최소값을 구한다.
				w=j; 
			}
		}

		if(min == 10000) break;
		chk[w]=1;	// 현재까지 구한 거리중 가장 짧은 길이므로 확정한다.

		for(int j = 1; j <= n; j++)
		{
			if(a[w][j] != 0) // 다른 곳에서 w 에 이르는 길이 있다면
			{
				int t = a[w][j] + di[w];
				if (di[j] > t) // 그 값이 그동안 w까지 온 거리(di[w])에 그 새로운 길(a[w][j])을 합한거보다 크다면(즉, 새길이 현재 최소거리라면)
				{
					di[j] = a[w][j] + di[w]; // 그곳에 이르는 최소거리를 업데이트한다.
					
					std::fill(visit[j], visit[j] + n + 1, 0);// 기존 방문목록 제거
					visit[j][w]++;			// j를 w에서 방문해옴
				}
				else if (di[j] == t)
				{
					visit[j][w]++;			// j를 w에서 방문해옴(여기선 초기화 안했으므로 여러경로가 중복될 것)
				}				
			}
		}
	}
}

 int Gcd(int u, int v)
 {
	 int shift;
	 if (u == 0 || v == 0)
	   return u | v;
 
	 for (shift = 0; ((u | v) & 1) == 0; ++shift) {
		 u >>= 1;
		 v >>= 1;
	 }
 
	 while ((u & 1) == 0)
	   u >>= 1;
 
	 do {
		 while ((v & 1) == 0) 
		   v >>= 1;
 
	  if (u > v) {
		 int t = v; v = u; u = t;}  
	  v = v - u;                
	 } while (v != 0);
 
	 return u << shift;
 }

int CalcCnt(int (*graph)[101], int* cnt, int s, int n)
{
	if (s == n)
	{
		++cnt[s];
		return 1;
	}

	int child = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (graph[i][s])
		{
			child += CalcCnt(graph, cnt, i, n);
		}
	}
	cnt[s] += child;
	return child;
}

int main()
{
	// 다익스트라를 수행하면서 새 노드들로 가지를 확장했을때
	// 새 길이 작을때 혹은 기존과 같을때(이때는 기존값과 새값 모두 저장) 어느 노드로 부터 방문했는지 기록을 남긴다.
	// 다익스트라가 끝나고 나면 거쳐온 그 기록을 기반으로 확률 계산
	int testN = 0;
	std::cin >> testN;
	for (int i = 0; i < testN; ++i)
	{
		int graph[101][101] = {0,};
		int n = 0;
		int v = 0;
		int e = 0;
		std::cin >> v >> e >> n;

		// 간선 정보를 받는다.
		int a = 0;
		int b = 0;
		int t = 0;
		for (int j = 0; j < e; ++j)
		{
			std::cin >> a >> b >> t;
			graph[a][b] = t;
		}
		
		// 다익스트라로 방문 가능한 경로를 구한다.
		int visit[101][101] = {0,};
		dijkstra(graph, v, visit);

		// 방문 경로를 역추적하여 각 정점마다의 확률을 구한다.
		int cnt[101] = {0,};
		int mod = CalcCnt(visit, cnt, 1, v);

		// 확률을 출력한다.
		for (int j = 0; j < n; ++j)
		{
			int n_1 = 0;
			std::cin >> n_1;
			int num = cnt[n_1];
			int gcd = Gcd(num, mod);

			if (gcd == 0)
			{
				std::cout << "0/1" << std::endl;
			}
			else
			{
				std::cout << num / gcd << "/" << mod / gcd << std::endl;
			}
		}
	}

	return 0;
}



/*
#include <cstdio> 
#include <climits> 
#include <vector> 

using namespace std; 

const int MAX = 100; 

struct edge 
{ 
	int to; 
	int weight; 
	
	edge(int to, int weight) 
		: to(to), weight(weight) { } 
}; 

vector<edge> es[MAX+1]; 
int dist[MAX+1]; 
vector<int> parent[MAX+1]; 
bool check[MAX+1]; 
long long cnt[MAX+1];
long long ncnt[MAX+1];
int v; 

long long gcd(long long a, long long b) 
{ 
	while (a%b!=0) 
	{ 
		long long t = a%b; 
		a = b; 
		b = t; 
	} 
	
	return b; 
}

void calc() 
{ 
	for (int i=1; i<=v; ++i) 
	{ 
		check[i] = false; 
		ncnt[i] = 0;
	} 
	
	ncnt[v] = cnt[v];

	for (int i=0; i<v; ++i) 
	{ 
		int m = -1; 
		int mi = -1; 
		
		for (int j=1; j<=v; ++j) 
		{ 
			if ( ! check[j] && dist[j] > m) 
			{ 
				m = dist[j]; 
				mi = j; 
			} 
		} 
		
		check[mi] = true; 
		if (parent[mi].size() > 0)
		{
			for (vector<int>::iterator j=parent[mi].begin(); j!=parent[mi].end(); ++j)
				ncnt[*j] += ncnt[mi] / cnt[mi] * cnt[*j];
		}
	} 
}

void dijkstra() 
{ 
	for (int i=1; i<=v; ++i) 
	{ 
		check[i] = false; 
		dist[i] = INT_MAX; 
		parent[i].clear();
		cnt[i] = 0;
	} 
	
	dist[1] = 0; 
	cnt[1] = 1;
	for (int i=0; i<v; ++i) 
	{ 
		int m = INT_MAX; 
		int mi = -1; 
		
		for (int j=1; j<=v; ++j) 
		{ 
			if ( ! check[j] && dist[j] < m) 
			{ 
				m = dist[j]; 
				mi = j; 
			} 
		} 
		
		check[mi] = true; 
		for (vector<edge>::iterator j=es[mi].begin(); j!=es[mi].end(); ++j) 
		{ 
			if ( ! check[j->to]) 
			{ 
				int nv = dist[mi] + j->weight; 
				if (nv < dist[j->to]) 
				{ 
					dist[j->to] = nv; 
					parent[j->to].clear(); 
					parent[j->to].push_back(mi);
					cnt[j->to] = cnt[mi];
				} 
				else if (nv == dist[j->to])
				{
					parent[j->to].push_back(mi);
					cnt[j->to] += cnt[mi];
				}
			} 
		}
	} 
} 

int main() 
{
	int c; 
	scanf("%d", &c); 
	while (c--) 
	{ 
		int e, n; 
		scanf("%d %d %d", &v, &e, &n); 
		for (int i=1; i<=v; ++i) 
			es[i].clear(); 
		
		for (int i=0; i<e; ++i) 
		{ 
			int a, b, t; 
			scanf("%d %d %d", &a, &b, &t); 
			es[a].push_back(edge(b, t)); 
			es[b].push_back(edge(a, t)); 
		} 
		
		dijkstra(); 
		calc(); 
		
		for (int i=0; i<n; ++i) 
		{ 
			int t; 
			scanf("%d", &t); 
			if (t==1 || t==v) 
				printf("1/1\n"); 
			else if (ncnt[t] == 0)
				printf("0/1\n");
			else 
			{
				long long g = gcd(ncnt[v], ncnt[t]);
				printf("%lld/", ncnt[t]/g); 
				printf("%lld\n", ncnt[v]/g);
			}
		} 
	} 
	
	return 0; 
} 
*/

