#include "stdafx.h"
#include "Fight.h"
#include "Draw.h"
#include "Person.h"
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

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

namespace GameCombat{
	vector<string> combatMenu(vector<int> playerStats, vector<double>npcStats);
	vector<double> attack(vector<int> playerStats, vector<double> npcStats, double effectiveSkill);
	vector<int> npcAttack(vector<double> npcStats, vector<int>playerStats, double effectiveSkill);
	int getDamage(int Stats1, int Stats2, int Stats3, int Stats4, int Skill);
	vector<string> drawEndCombat(vector<int> playerStats, vector<double> npcStats);
	vector<int> selectPrompt(vector<int> playerStats);
	vector<int> getInput();
	vector<int> skillSelect(int key, int key3);
	bool gameOver();
	void drawFight(vector<int> playerStats, vector<double> npcStats);
}