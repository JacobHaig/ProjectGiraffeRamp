#pragma once
#include "Common.h"

using namespace std;

enum mapSelect
{
	saveMenu, Map1, Map2, Map3, Map4, playerInfo, pauseMenu, fightScreen, combatMenu
};

namespace Maps {
	vector<Person*> Entities1();
	vector<Person*> Entities2();
	vector<Person*> Entities3();
	vector<Person*> Entities4();

	vector<string> getMap(int);
	char getCharPos(int selection, int x, int y);
	void initMaps();
}