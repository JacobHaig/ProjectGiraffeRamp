#pragma once
#include "Person.h"
#include <vector>
#include <string>
#include <iostream>



namespace Utilities {

	int vectorObjIndex(string Name, std::vector<Person*> thisVector);
	string checkPos(vector<Person*> thisVector); //checks if the Pos of X and Y of both Pointers are equal
	vector<string> checkMap(vector<Person*> thisVector, vector<string> Map);
	void SleepNow(int MS);
	void rememberEntities(vector<string> curMap, vector<string>lastMap, vector<Person*> curEnt, vector<Person*> ent1, vector<Person*>ent2, vector<Person*>ent3, vector<Person*>ent4);
	vector<Person*> movePlayerOnMapChange(vector<string> curMap, vector<string>lastMap, vector<Person*> Entities, vector<Person*> ent1, vector<Person*>ent2, vector<Person*>ent3, vector<Person*>ent4);
	COORD randPos(int x, int xx, int y, int yy);
	void PlayMusic(wstring song);
}

