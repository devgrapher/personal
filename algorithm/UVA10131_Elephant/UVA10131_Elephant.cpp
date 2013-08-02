// UVA10131_Elephant.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Eelephant
{
	int idx;
	int weight;
	int iq;
};

bool CompareEle(Eelephant& el1, Eelephant& el2)
{
	return el1.weight < el2.weight;
};


int _tmain(int argc, _TCHAR* argv[])
{

	while (std::cin.eof() == false && std::cin.fail() == false)
	{
		std::vector<Eelephant> elephants;

		for (int i = 0; i < 1000; ++i)
		{
			std::string line;
			std::getline(std::cin, line);
			std::istringstream in(line);

			if (line.empty())
			{
				break;
			}

			Eelephant el;
			el.idx = i;
			in >> el.weight;
			in >> el.iq;
			elephants.push_back(el);
		}
		
		// 무게를 기준으로 정렬
		std::sort(elephants.begin(), elephants.end(), CompareEle);

		int dy[1000][2] = {0,};
		enum DY_VAL
		{
			CNT, // 연속되는 시퀀스 수
			POS, // 자신의 앞 시퀀스 번호
		};

		for (int i = 0; i < elephants.size(); ++i)
		{
			dy[i][CNT] = 1;
			dy[i][POS] = -1; // 기본값
			int max = 0;
			for (int j = i - 1; j >= 0; --j)
			{
				if (elephants[j].iq > elephants[i].iq && // 자기보다 크고
					elephants[j].weight < elephants[i].weight) // 무게가 작으면(같은경우 필터링)
				{
					if (max < dy[j][CNT])
					{
						max = dy[j][CNT];
						dy[i][CNT] = max + 1;
						dy[i][POS] = j;
					}
				}
			}
		}

		// 결과테이블에서 최대 카운트를 가진 수열을 찾는다.
		int max = 0;
		int maxIdx = 0;
		for (int i = 0; i < elephants.size(); ++i)
		{
			if (dy[i][CNT] > max)
			{
				max = dy[i][CNT];
				maxIdx = i;
			}
		}

		// 최대 길이 출력
		std::cout << max << std::endl;

		int idx = maxIdx;
		std::vector<int> result;
		while (idx != -1)
		{
			result.push_back(elephants[idx].idx + 1); // 인덱스가 0에서 시작했으므로 1 더해줌
			idx = dy[idx][POS];
		}

		// 각 시퀀스 출력
		for (int i = result.size() - 1; i >= 0; --i) // 역순으로 출력한다.
		{
			std::cout << result[i] << std::endl;
		}

	}

	return 0;
}

