// Baseball.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

struct Team
{
	int win;
	int ross;
};


int _tmain(int argc, _TCHAR* argv[])
{
	int cases;
	std::wcin >> cases;
	for (int i = 0; i < cases; ++i)
	{
		// 팀정보 초기화
		std::map<std::wstring, Team> teams;
		for (int j = 0; j < 8; ++j)
		{
			Team t;
			int win, draw, loss;
			wchar_t name[21] = {0,};
			std::wcin >> name >> win >> draw >> loss;
			t.win = win;
			t.ross = draw + loss;
			teams.insert(std::make_pair(name, t));
		}
		wchar_t myteam[21] = {0,};
		std::wcin >> myteam;

		// 게임 진행
		int games;
		std::wcin >> games;
		for (int j = 0; j < games; ++j)
		{
			wchar_t t1[21] = {0,};
			wchar_t t2[21] = {0,};
			std::wcin >> t1 >> t2;
			
			std::map<std::wstring, Team>::iterator team1 = teams.find(t1);
			std::map<std::wstring, Team>::iterator team2 = teams.find(t2);
			if (wcscmp(t1, myteam) == 0)
			{
				team1->second.win++;
				team2->second.ross++;
			}
			else if (wcscmp(t2, myteam) == 0)
			{
				if (wcscmp(t2, myteam) == 0)
				{
					team1->second.ross++;
					team2->second.win++;
				}
			}
			else
			{
					team1->second.ross++;
					team2->second.ross++;
			}
		}

		// 결과 비교
		std::map<std::wstring, Team>::iterator myIt = teams.find(myteam);
		double myWin = myIt->second.win / (double)(myIt->second.win + myIt->second.ross);
		int upperCnt = 0;
		for (std::map<std::wstring, Team>::iterator it = teams.begin(); it != teams.end(); ++it)
		{
			if (myIt == it)
			{
				continue;
			}
			double win = it->second.win / (double)(it->second.win + it->second.ross);;
			if (myWin < win)
			{
				upperCnt++;
			}
		}
		
		std::cout << (upperCnt < 4 ? "YES" : "NO") << std::endl;

	}
	return 0;
}

