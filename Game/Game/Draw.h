#pragma once
#include "Person.h"
#include "Common.h"

namespace Draw {
	void drawVectorEntities(int entSelected, int selection);
	void drawMainMenu();
	void drawYourStats();
	void drawFightStats(string yourName, string enemyName, int yourHealth, int enemyHealth);
	void drawLore();
	void drawCredits();
	void drawVectorMaps(int selection);
	void changeCursorProperties(int i, int j, char &charactor);
};