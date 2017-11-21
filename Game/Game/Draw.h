#pragma once
#include "Person.h"
#include "Common.h"

namespace Draw {
	void drawVectorEntities(vector<Person*> Entities, int selection);
	void drawMainMenu();
	void drawYourStats(vector<Person*> Ent1, vector<Person*> Ent2, vector<Person*> Ent3, vector<Person*> Ent4);
	void drawFightStats(string yourName, string enemyName, int yourHealth, int enemyHealth);
	void drawLore();
	void drawCredits();
	void drawVectorMaps(int selection);
	void changeCursorProperties(int i, int j, char &charactor);
};