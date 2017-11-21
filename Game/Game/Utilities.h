#pragma once
#include "Person.h"
#include "Common.h"



namespace Utilities {

	int vectorObjIndex(string Name, std::vector<Person*> thisVector);
	string checkPos(vector<Person*> thisVector); //checks if the Pos of X and Y of both Pointers are equal
	int changeMap(Person* name, int selection);
	int checkMap(vector<Person*> thisVector, int selection);
	void SleepNow(int MS);
	void rememberEntities(vector<string> curMap, vector<string>lastMap, vector<Person*> curEnt, vector<Person*> ent1, vector<Person*>ent2, vector<Person*>ent3, vector<Person*>ent4);
	vector<Person*> movePlayerOnMapChange(int curMapSelected, int lastMapSelected, vector<Person*> Entities, vector<Person*> ent1, vector<Person*>ent2, vector<Person*>ent3, vector<Person*>ent4);
	COORD randPos(int x, int xx, int y, int yy);
	void PlayMusic(wstring song);
}

