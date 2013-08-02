// PCC50_Maze.cpp : Defines the entry point for the console application.
//


// 미로 최단거리, 프로그래밍 컨테스트 챌린징 50p
// 너비우선 탐색으로 모든 길을 방문한다.
// 깊이 우선 탐색은 같은길을 몇번이고 지나가기 때문에 너비우선 탐색이 낫다.

#include "stdafx.h"
#include <queue>
#include <iostream>
#include <sstream>



int g_table[101][101] = {0,};
int g_dist[101][101] = {0,};
int DIRECT[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

typedef std::pair<int,int> POS;
std::queue<POS> que;

void BFS(POS pos)
{
	que.push(pos);

	while(que.empty() == false)
	{
		POS cur = que.front();
		que.pop();

		// 방문
		if (g_table[cur.first][cur.second] == 2) // 종점이라면 그만
		{
			continue;
		}

		// 자식 삽입
		for (int i = 0; i < 4; ++i)
		{
			POS child = std::make_pair(DIRECT[i][0] + cur.first, DIRECT[i][1] + cur.second);
			if (g_table[child.first][child.second])
			{
				if (g_dist[child.first][child.second])
				{
					continue; // 방문한 노드
				}
				g_dist[child.first][child.second] = g_dist[cur.first][cur.second] + 1; // 현재노드까지 거리 입력.
				que.push(child);
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int N,M = 0;
	std::wcin >> N >> M;

	// 입력 처리

	std::wstring line; 
	std::getline(std::wcin, line); // 라인하나 무시

	POS start;
	POS end;
	for (int i = 0; i < N; ++i)
	{
		std::getline(std::wcin, line);

		if (line.length() < M)
		{
			continue;
		}
		for (int j = 0; j < M; ++j)
		{
			switch (line[j])
			{
			case L'#':
				g_table[i+1][j+1] = 0;
				break;
			case L'S':
				start = std::make_pair(i+1, j+1);
				g_table[i+1][j+1] = 1;
				break;
			case L'G':
				g_table[i+1][j+1] = 2;
				end = std::make_pair(i+1, j+1);
				break;
			default:
				g_table[i+1][j+1] = 1;
			}
		}
	}

	// 처리
	BFS(start);

	std::wcout << g_dist[end.first][end.second] << std::endl;

	return 0;
}

