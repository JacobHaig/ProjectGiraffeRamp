#pragma once
#include "Person.h"
#include <iostream>
#include <string>
#include <vector>

namespace Draw {
	void drawEntities(vector<Person*> Entities);
	void drawEntities(vector<Person*> Entities, vector<string> Map);
	void drawMap(vector<string> Map);
	void drawMainMenu();
	void drawYourStats(vector<Person*> Ent1, vector<Person*> Ent2, vector<Person*> Ent3, vector<Person*> Ent4);
	void drawFightStats(string yourName, string enemyName, int yourHealth, int enemyHealth);
	void drawLore();
	void drawCredits();
	void drawEnemyStats();
};

