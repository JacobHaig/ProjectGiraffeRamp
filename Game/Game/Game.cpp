#include "stdafx.h"
#include "Person.h"
#include "Maps.h"
#include "Utilities.h"
#include "Draw.h"
#include "Movement.h"
#include "Fight.h"
#include "SaveLoadGame.h"
#include "Common.h"

using namespace std;


//main function
void main() {
	//Draw::drawMainMenu();

	Maps::initMaps();
	//Draw::drawVectorMaps(mapSelect::Map1);
	// ADD new Game prompt

	string yourName = "Gary 25";

	vector<Person*> curEnt = Maps::Entities1(), ent1 = Maps::Entities1();
	vector<Person*> ent2 = Maps::Entities2();
	vector<Person*> ent3 = Maps::Entities3();
	vector<Person*> ent4 = Maps::Entities4();

	int currentMapSelected = mapSelect::Map1;
	auto lastMapSelected = currentMapSelected;

	string statsFilename = "TheStats.txt", npcInfoFile = "npcs.txt";
	vector<int> playerStats = SaveLoad::playerStatsLoadMain();

	Draw::drawVectorMaps(mapSelect::playerInfo);
	Draw::drawVectorMaps(currentMapSelected);
	Draw::drawVectorEntities(curEnt, currentMapSelected);
	Draw::drawYourStats(ent1, ent2, ent3, ent4);

	while (true) {
		Draw::drawVectorEntities(curEnt, currentMapSelected);           // draws all units only if they are on a blank spot on the map
		curEnt[Utilities::vectorObjIndex(" ", curEnt)]->setPos(curEnt[Utilities::vectorObjIndex("@", curEnt)]->getPos());
		Movement::move(Movement::getInput(), curEnt, currentMapSelected);
		
		currentMapSelected = Utilities::checkMap(curEnt, currentMapSelected); // checks if your char is on maps border, if so than push if back to previous pos.

		if (currentMapSelected != lastMapSelected) {		// if the map is changed. change the entities in use and move your char to the correct portal.
															// Saves current entities to current entities' map
			{
				if (lastMapSelected == mapSelect::Map1) ent1 = curEnt;// saves entities if moving to differant map 
				if (lastMapSelected == mapSelect::Map2) ent2 = curEnt;
				if (lastMapSelected == mapSelect::Map3) ent3 = curEnt;
				if (lastMapSelected == mapSelect::Map4) ent4 = curEnt;
			}

			curEnt = Utilities::movePlayerOnMapChange(currentMapSelected, lastMapSelected, curEnt, ent1, ent2, ent3, ent4);
			lastMapSelected = currentMapSelected;		// set lastMap to current map 
		}

		{		// Saves current entities to current entities' map
			if (currentMapSelected == mapSelect::Map1) ent1 = curEnt;// saves entities if moving to differant map 
			if (currentMapSelected == mapSelect::Map2) ent2 = curEnt;
			if (currentMapSelected == mapSelect::Map3) ent3 = curEnt;
			if (currentMapSelected == mapSelect::Map4) ent4 = curEnt;
		}
		Draw::drawYourStats(ent1, ent2, ent3, ent4);
		if (Utilities::checkPos(curEnt).compare("Nope")) {// if one of units coords is identical to another than do stuff
			system("CLS");
			Fight::fight(curEnt, curEnt[Utilities::vectorObjIndex(Utilities::checkPos(curEnt), curEnt)]->RealName, yourName, playerStats, statsFilename);
			curEnt.erase(curEnt.begin() + Utilities::vectorObjIndex(Utilities::checkPos(curEnt), curEnt));
			//Draw::drawCredits(); only to test the credits
		}
	}
	Draw::drawCredits();
	_getch();
}



