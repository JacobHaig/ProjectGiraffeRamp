#include "stdafx.h"
#include "Person.h"
#include "maps.h"
#include "Draw.h"
#include "Common.h"

using namespace std;

namespace Utilities {

	// Returns the index of the vector of Persons that have the same name
	int vectorObjIndex(entSelect entsSelected, string Name) { //looks for pointer in vector with a name of Name then returns the Position
		auto ents = Ents::getEnt(entsSelected);
		int counter = 0;
		for each (Person* obj in ents) {
			if (Name == obj->Name)
				return counter;
			counter++;
		}
		return -1;
	}

	// Returns the index of the vector of Persons that have the same name
	Person* vectorObjEnt(entSelect entsSelected, string Name) { //looks for pointer in vector with a name of Name then returns the Position
		auto ents = Ents::getEnt(entsSelected);
		for each (Person* obj in ents)
			if (Name == obj->Name)
				return obj;
	}

	// Returns name if two ents share the same pos else returns "Nope"
	string checkPos(vector<Person*> thisVector) {   //checks if the Pos of X and Y of both Pointers are equal
		for each (Person* name in thisVector) {
			COORD Pos2 = name->getPos();
			COORD Pos1 = thisVector[Utilities::vectorObjIndex("@", thisVector)]->getPos();

			// Makes sure we don't fight our Follower 
			if (Pos2.X == Pos1.X && Pos2.Y == Pos1.Y && (name->Name != " " && name->Name != "@"))
				return name->Name;
		}

		return "Nope";
	}

	// changeMap function
	int changeMap(Person* name, int selection) {	// 1 3
													// 2 4
		auto Map = Maps::getMap(selection);

		if (mapSelect::Map1 == selection && name->getPosY() > 20) // Map 1 to 2
			return mapSelect::Map2;
		if (mapSelect::Map1 == selection && name->getPosX() > 115)// Map 1 to 3
			return mapSelect::Map3;

		if (mapSelect::Map2 == selection && name->getPosY() < 5)  // Map 2 to 1  
			return mapSelect::Map1;
		if (mapSelect::Map2 == selection && name->getPosX() > 115)// Map 2 to 4
			return mapSelect::Map4;

		if (mapSelect::Map3 == selection && name->getPosX() < 5)// Map 3 to 1
			return mapSelect::Map1;
		if (mapSelect::Map3 == selection && name->getPosY() > 20)// Map 3 to 4
			return mapSelect::Map4;

		if (mapSelect::Map4 == selection && name->getPosX() < 5)// Map 4 to 2
			return mapSelect::Map2;
		if (mapSelect::Map4 == selection && name->getPosY() < 5)// Map 4 to 3
			return mapSelect::Map3;

		return 0;
	}

	// Check for a collision with a wall or portal, if so return
	void checkMap(int &entsSelected, int &mapsSelection) {
		auto ents = Ents::getEnt(entsSelected);

		Person* personMe = Utilities::vectorObjEnt(ents, "@");
		COORD Pos = personMe->getPos();

		Person* follower = Utilities::vectorObjEnt(ents, " ");
		COORD lastPos = follower->getPos();

		if (Maps::getCharPos(mapsSelection, Pos.Y, Pos.X) == '*') {
			auto selection = changeMap(personMe, mapsSelection);
			entsSelected = selection;
			mapsSelection = selection;
		}
		if (Maps::getCharPos(mapsSelection, Pos.Y, Pos.X) != ' ') {
			personMe->setPos(lastPos);
			follower->setPos(Pos);
			Draw::drawVectorEntities(entsSelected, mapsSelection);
		}
	}

	// Stop this thread
	void SleepNow(int MS) {
		this_thread::sleep_for(chrono::milliseconds(MS));
	}

	// Adjusts the players position on map change
	vector<Person*> movePlayerOnMapChange(int curMap, int lastMap, vector<Person*> curEnt, vector<Person*> ent1, vector<Person*> ent2, vector<Person*> ent3, vector<Person*> ent4) {

		COORD pos;
		if (curMap == mapSelect::Map2 && lastMap == mapSelect::Map1) {
			curEnt = ent2;
			pos = { 45, 1 };
		}
		if (curMap == mapSelect::Map3 && lastMap == mapSelect::Map1) {
			curEnt = ent3;
			pos = { 2, 11 };
		}
		if (curMap == mapSelect::Map1 && lastMap == mapSelect::Map2) {
			curEnt = ent1;
			pos = { 45, 21 };
		}
		if (curMap == mapSelect::Map4 && lastMap == mapSelect::Map2) {
			curEnt = ent4;
			pos = { 2, 11 };
		}
		if (curMap == mapSelect::Map1 && lastMap == mapSelect::Map3) {
			curEnt = ent1;
			pos = { 117, 11 };
		}
		if (curMap == mapSelect::Map4 && lastMap == mapSelect::Map3) {
			curEnt = ent4;
			pos = { 60, 1 };
		}
		if (curMap == mapSelect::Map3 && lastMap == mapSelect::Map2) {
			curEnt = ent3;
			pos = { 61, 21 };
		}
		if (curMap == mapSelect::Map2 && lastMap == mapSelect::Map4) {
			curEnt = ent2;
			pos = { 117, 11 };
		}

		curEnt[Utilities::vectorObjIndex("@", curEnt)]->setPos(pos);
		system("CLS");			//clear the screen
		Draw::drawVectorMaps(mapSelect::playerInfo);
		Draw::drawVectorMaps(curMap);

		return curEnt;
	}


	COORD randPos(int xrand, int xoff, int yrand, int yoff) {
		COORD pos;
		static int random = 0;
		srand((unsigned int)time(0) + random);
		random = rand();

		// x/y rand can not be 0
		pos.X = rand() % xrand + xoff;
		pos.Y = rand() % yrand + yoff;

		return pos;
	}

	void PlayMusic(wstring song) {
		// uncommenting crashes the program
		//PlaySound(song.c_str(), NULL, SND_FILENAME | SND_ASYNC);
	}
}