#pragma once
#include "Common.h"

using namespace std;

enum mapSelect
{
	saveMenu, Map1, Map2, Map3, Map4, playerInfo, pauseMenu, fightScreen, combatMenu
};

enum entSelect
{
	ent1, ent2, ent3, ent4
};

namespace Maps {

	vector<string> getMap(int);
	char getCharPos(int selection, int x, int y);
	void initMaps();
}

namespace Ents {
	void removeEnt(entSelect selectedEnts, int entIndex);
	void changeEntsPos(entSelect selectedEnts, int entIndex, COORD pos);
	void initEntities();
	vector<Person*> getEnt(int index);
}