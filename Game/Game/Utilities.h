#pragma once
#include "Person.h"
#include "maps.h"
#include "Common.h"

namespace Utilities {
	int vectorObjIndex(entSelect entsSelected, string Name);
	Person* vectorObjEnt(entSelect entsSelected, string Name);
	string checkPos(entSelect selected); //checks if the Pos of X and Y of both Pointers are equal
	int changeMap(Person* name, int selection);
	void checkMap(entSelect &entsSelected, mapSelect &mapsSelection);
	void SleepNow(int MS);
	entSelect movePlayerOnMapChange(int curMap, int lastMap, entSelect ent);
	COORD randPos(int x, int xx, int y, int yy);
	void PlayMusic(wstring song);
}