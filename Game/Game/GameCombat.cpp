#include "stdafx.h"
#include "GameCombat.h"
#include "Fight.h"
#include "Draw.h"
#include "maps.h"
#include "Person.h"
#include "SaveLoadGame.h"
#include "Common.h"

/*TO DO:
Create a combat header file for attack commands and interaction with entities.
Create Save/Load header file to save file commands
*/
/*FUNCTIONS:
combatMenu : stores the map for the combat screen
attack : takes in playersStats, npcStats and effectiveSkill - returns npcStats as damage
npcAttack : takes in npcStats, playerStats and effectiveSkill - returns playerStats as damage
getDamage : takes in Stats1, Stats2, Stats3, Stats4, and Skill - returns damage based off multiplier
*/
/*PRIMARY VARIABLES
playerStats : 0 = HP, 1 = ARM, 2 = ATK, 3 = ENG, 4 = ELM, 5 = LEVEL, 6 = Name, 7 = Skill1, 8 = Skill2, 9 = Skill3, 10 = Skill4
npcStats : 0 = HP, 1 = ARM, 2 = ATK, 3 = ENG, 4 = ELM, 5 = LEVEL, 6 = Name, 7 = Skill1, 8 = Skill2, 9 = Skill3
playerMultiplier = represents player damage multiplier for attacks
*/



namespace GameCombat {
	vector<int> playerStats, npcStats;
	string statsFilename, playerName;

	//Begin combatDraw function
	//Draw skill menu and combat box


	//optimally 4-6 skills, at the bottom of the screen
	//pulls skills from player save file
	//Draw player image (default image or possibly sex based)
	//Draw NPC image
	//use npc identifier to select from designed images
	//load selected npc image 
	//End Draw combat elements function


	vector<double> attack(vector<int> playerStats, vector<double> npcStats, double effectiveSkill) {
		//Begin Attack function
		//pulls data from selected player skill. key values (effectiveSkill - determines the multipler of the skills damage, pulled from the skills data)

		int totalDamage = (int)getDamage(playerStats[4], npcStats[4], playerStats[2], npcStats[1], effectiveSkill);

		//Display player attack animation
		//Damage is resolved
		npcStats[0] -= totalDamage;

		return npcStats;
	}

	vector<int> npcAttack(vector<double> npcStats, vector<int>playerStats, double effectiveSkill) {
		//Begin Attack function
		//pulls data from selected player skill. key values (effectiveSkill - determines the multipler of the skills damage, pulled from the skills data)
		int totalDamage = (int)getDamage(npcStats[4], playerStats[4], playerStats[2], npcStats[1], effectiveSkill);

		//Display player attack animation
		//Damage is resolved
		playerStats[0] -= totalDamage;

		return playerStats;
	}

	int getDamage(int Stats1, int Stats2, int Stats3, int Stats4, int Skill) {
		if (Stats1 == 1) {
			if (Stats2 == 1)
				return (int) Stats3 - Stats4;
			if (Stats2 == 2)
				return (int) Stats3 * Skill - Stats4;
			if (Stats2 == 3)
				return (int) Stats3 - Stats4;
			if (Stats2 == 4)
				return (int) Stats3 * 0.5;
		}
		if (Stats1 == 2) {
			if (Stats2 == 1)
				return (int) Stats3 * 0.5;
			if (Stats2 == 2)
				return (int) Stats3 - Stats4;
			if (Stats2 == 3)
				return (int) Stats3 * Skill - Stats4;
			if (Stats2 == 4)
				return (int) Stats3 - Stats4;
		}
		if (Stats1 == 3) {
			if (Stats2 == 1)
				return (int) Stats3 - Stats4;
			if (Stats2 == 2)
				return (int) Stats3 * 0.5;
			if (Stats2 == 3)
				return (int) Stats3 - Stats4;
			if (Stats2 == 4)
				return (int) Stats3 * Skill - Stats4;
		}
		if (Stats1 == 4) {
			if (Stats2 == 1)
				return (int) Stats3 * Skill - Stats4;
			if (Stats2 == 2)
				return (int) Stats3 - Stats4;
			if (Stats2 == 3)
				return (int) Stats3 * 0.5;
			if (Stats2 == 4)
				return (int) Stats3 - Stats4;
		}
		return 1;
	}

	vector<int> selectPrompt(vector<int> playerStats) {
		string confirmMessage = "Press twice to confirm your selection!";
		vector<int> playerInput;
		playerInput = GameCombat::getInput();

		if (playerInput[0] == playerInput[1] && playerInput[2] == playerInput[3])
			GameCombat::skillSelect(playerInput[0], playerInput[2]);
		else if (playerInput[0] != playerInput[1] || playerInput[2] != playerInput[3])
			playerInput = GameCombat::getInput();

		return playerStats;
	}

	vector<int> getInput() {
		int key = _getch();
		int key2 = _getch();
		int key3 = _getch();
		int key4 = _getch();

		vector<int>inputInt = { key, key2, key, key4 };
		return inputInt;
	}


	bool gameOver() {
		// if(enemyhealth <= 0) return true;
		return false;
	}


	vector<int> skillSelect(int key, int key3) {
		playerStats[key + 6] = npcStats[key3 + 6];
		SaveLoad::playerStatsSave(playerStats, statsFilename, playerName);

		return playerStats;
	}

	void drawFight(vector<int> playerStats, vector<double> npcStats) {
		auto map = Maps::getMap(mapSelect::combatMenu);

		for (short i = 0; i < map.size(); i++)
			for (short j = 0; j < map[i].length(); j++)
			{
				char name = map[i][j];
				if (name == '#') {
					name = char(219);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 | FOREGROUND_INTENSITY);
				}

				if (name == 'i')
					name = char(218);
				if (name == 'k')
					name = char(192);
				if (name == 'o')
					name = char(191);
				if (name == 'l')
					name = char(217);
				cout << name;
			}
	}

}