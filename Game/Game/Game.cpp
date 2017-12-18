#include "stdafx.h"
#include "Person.h"
#include "Maps.h"
#include "Utilities.h"
#include "Draw.h"
#include "Movement.h"
#include "Fight.h"
#include "SaveLoadGame.h"
#include "Common.h"

#define entNamed(x, curEnt) Utilities::vectorObjIndex(x, curEnt)

using namespace std;


//main function
void main() {
	//Draw::drawMainMenu();

	Maps::initMaps();
	Ents::initEntities();

	//Draw::drawVectorMaps(mapSelect::Map1);
	// ADD new Game prompt

	//Maps::getEnt(entSelect::ent1); wont work needs a rewrite to implament

	string yourName = "Gary 25";

	entSelect selectedEnt = entSelect::ent1;
	vector<Person*> curEnt = Ents::getEnt(entSelect::ent1), ent1 = Ents::getEnt(entSelect::ent1);
	vector<Person*> ent2 = Ents::getEnt(entSelect::ent2);
	vector<Person*> ent3 = Ents::getEnt(entSelect::ent3);
	vector<Person*> ent4 = Ents::getEnt(entSelect::ent4);

	mapSelect currentMapSelected = mapSelect::Map1;
	auto lastMapSelected = currentMapSelected;

	string statsFilename = "TheStats.txt", npcInfoFile = "npcs.txt";
	vector<int> playerStats = SaveLoad::playerStatsLoadMain();

	Draw::drawVectorMaps(mapSelect::playerInfo);
	Draw::drawVectorMaps(currentMapSelected);
	Draw::drawVectorEntities(selectedEnt, currentMapSelected);
	Draw::drawYourStats();

	while (true) {
		Draw::drawVectorEntities(selectedEnt, currentMapSelected);								// draws all units only if they are on a blank spot on the map
		Ents::changeEntsPos(selectedEnt, Utilities::vectorObjIndex(selectedEnt, " "), Utilities::vectorObjEnt(selectedEnt, "@")->getPos());
		Movement::move(Movement::getInput(), selectedEnt, currentMapSelected);
		Utilities::checkMap(curEnt, currentMapSelected);				// checks if your char is on maps border, if so than push if back to previous pos.

		if (currentMapSelected != lastMapSelected) {					// if the map is changed. change the entities in use and move your char to the correct portal.
			curEnt = Utilities::movePlayerOnMapChange(currentMapSelected, lastMapSelected, curEnt, ent1, ent2, ent3, ent4);
			lastMapSelected = currentMapSelected;		// set lastMap to current map 
		}

		Draw::drawYourStats(ent1, ent2, ent3, ent4);
		if (Utilities::checkPos(curEnt).compare("Nope")) {// if one of units coords is identical to another than do stuff
			system("CLS");
			Fight::fight(curEnt, curEnt[entNamed(Utilities::checkPos(curEnt), curEnt)]->RealName, yourName, playerStats, statsFilename);
			curEnt.erase(curEnt.begin() + entNamed(Utilities::checkPos(curEnt), curEnt));
			//Draw::drawCredits(); only to test the credits
		}
	}
	Draw::drawCredits();
	_getch();
}



