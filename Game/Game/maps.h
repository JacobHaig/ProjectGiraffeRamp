#pragma once
#include "Common.h"

using namespace std;



enum mapSelect
{
	saveMenu, Map1, Map2, Map3, Map4, playerInfo, pauseMenu, fightScreen
};


namespace Maps {
	vector<Person*> Entities1();
	vector<Person*> Entities2();
	vector<Person*> Entities3();
	vector<Person*> Entities4();
	vector<string> pauseMenu();
	vector<string> playerInfo();
	vector<string> Map1();
	vector<string> Map2();
	vector<string> Map3();
	vector<string> Map4();
	vector<string> saveMenu();
	
	//vector<vector<string>> maps;
	vector<string> getMap(int);
	char getCharPos(int selection, int x, int y);
	void initMaps();
}
namespace Enemies {
	vector<string> Enemy1();
	vector<string> Enemy2();
	vector<string> Enemy3();
	vector<string> Enemy4();
}

