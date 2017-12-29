#include "stdafx.h"
#include "SaveLoadGame.h"

#define one 49
#define two 50
#define three 51
#define four 52



/*TO DO:
Create starting player skills
Create starting options for players
Create algorithm to determine player element
*/
/*FUNCTIONS:
playerStatsLoad : loads the players stats to the playerStats integer and returns playerStats
playerInfoLoad : loads the players information to the playerInfo string and returns playerInfo
npcStatsLoad : loads the npcs stats to the npcStats integer and returns npcStats
npcInfoLoad : loads the npcs info to the npcInfo string and returns npcInfo
*/
/*PRIMARY VARIABLES:
playerStats : 0 = HP, 1 = ARM, 2 = ATK, 3 = ENG, 4 = ELM, 5 = LEVEL, 6 = Name, 7 = Skill1, 8 = Skill2, 9 = Skill3, 10 = Skill4
npcStats : 0 = HP, 1 = ARM, 2 = ATK, 3 = ENG, 4 = ELM, 5 = LEVEL, 6 = Name, 7 = Skill1, 8 = Skill2, 9 = Skill3
playerMultiplier = represents player damage multiplier for attacks
inputPlayerStats : gathers player stats from database
inputNpc : gathers npc data from database
*/

using namespace std;

namespace SaveLoad {
	vector<int> playerStats[10], npcStats[10];

	//playerStatsLoadMain function
	vector<int> playerStatsLoadMain() {
		vector<int> playerStats;
		string statsFilename, str;
		COORD pos = { 48, 11 };

		Draw::drawVectorMaps(mapSelect::saveMenu);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

		do
			cin >> statsFilename;
		while (statsFilename.length() > 16 || statsFilename.length() < 0);// The file name must be a realistic

		statsFilename += ".txt";
		ifstream outputPlayerInfo(statsFilename);

		if (!outputPlayerInfo) {		// If the file name doesn't exist  we need to make one
			outputPlayerInfo.close();
			ofstream createPlayerInfo(statsFilename);

			for each(int i in choosePlayerClass()/*these may need to be changed*/)
				createPlayerInfo << i << "\n";

			createPlayerInfo.close();
			outputPlayerInfo.open(statsFilename);
		}

		while (getline(outputPlayerInfo, str))
			playerStats.push_back(stoi(str));

		outputPlayerInfo.close();
		system("CLS");

		return playerStats;
	}

	//playerStatsLoad function
	void playerStatsLoad(vector<int> &playerStats, string statsFilename) {
		int count = 0;
		ifstream inputPlayerStats(statsFilename);

		while (count < 10 && inputPlayerStats >> playerStats[count])
			count++;
		inputPlayerStats.close();

	}

	//playerStatsSave function
	vector<int> playerStatsSave(vector<int> playerStats, string statsFilename, string playerName) {
		int count = 0;
		ofstream outputPlayerInfo(statsFilename);

		while (count <= 10 && outputPlayerInfo << playerStats[count])
			count++;
		outputPlayerInfo.close();

		return playerStats;
	}

	//npcStatsLoad function
	void npcStatsLoad(vector<double> &npcStats, vector<int> &playerStats) {
		//add NPCspell randomize pulling from spell file.
		int MAX_SPELL = 104, MIN_SPELL = 1, MAX_MULTI = 9, MIN_MULTI = 1, MAX_MULTIX = 5;
		srand((unsigned)time(0));

		int multiplierSeed = (rand() % (MAX_MULTI - MIN_MULTI + 1)) + MIN_MULTI;
		int levelSeed = (int)(rand() % (MAX_MULTIX - MIN_MULTI + 1)) + MIN_MULTI;
		int levelMultiplier = multiplierSeed * 0.025 + 0.875;
		int npcMultiplier = levelSeed * 0.5 - 0.5;
		int npcUp = (int)npcMultiplier * playerStats[5];

		/* original npcMultiplier score
		switch (levelSeed) {
		case 1: npcMultiplier = 0.250;
		case 2: npcMultiplier = 0.500;
		case 3: npcMultiplier = 1.000;
		case 4: npcMultiplier = 1.500;
		case 5: npcMultiplier = 2.000; }*/

		npcStats[ARM] = (int)(playerStats[ARM] * .60) * levelMultiplier;
		npcStats[ATK] = (int)(playerStats[ATK] * .60) * levelMultiplier;
		npcStats[LEVEL] = (int)playerStats[LEVEL] + npcUp;
		npcStats[HP] = (int)max(playerStats[HP] * .4 * playerStats[LEVEL] * .4, 1);
		npcStats[Skill1] = (int)(rand() % (MAX_SPELL - MIN_SPELL + 1) + MIN_SPELL) - 1;

		if (npcStats[Skill1] == npcStats[Skill2])
			npcStats[Skill2] = (int)(rand() % (MAX_SPELL - MIN_SPELL + 1)) + MIN_SPELL;
		if (npcStats[Skill3] == npcStats[Skill1] || npcStats[Skill3] == npcStats[2])
			npcStats[Skill3] = (int)(rand() % (MAX_SPELL - MIN_SPELL + 1)) + MIN_SPELL;

	}

	// choosePlayerClass function
	vector<int> choosePlayerClass() {
		int key, key2;
		COORD pos = { 20, 11 }, pos2 = { 48 , 13 };		// { x , y } but has weird scaling
		string resetMessage = "Input incorrect, please try again!";

		system("CLS");
		//Draw::drawMap(Maps::classSelect());
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << "Press 1 for FireMage, 2 for WaterMage, 3 for EarthMage, 4 for WindMage...";

		do
			do {
				key = _getch();
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
				cout << "Press again to confirm...";
				key2 = _getch();

				if (key == key2)
					switch (key) {
					case one: return  { 15, 3, 8, 0, 1, 1, 0, 0, 1, 2, 3 };	//return vector<int> playerStats
					case two: return  { 15, 3, 8, 0, 2, 1, 0,78,79,80,81 };
					case three: return{ 15, 3, 8, 0, 3, 1, 0,26,27,28,29 };
					case four: return { 15, 3, 8, 0, 4, 1, 0,52,53,54,55 };
					}

				if (key != key2)
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
				cout << resetMessage;

			} while (key != one || key != two || key != three || key != four);

			while (key != key2);

			return{ 15, 3, 8, 0, 1, 1, 0, 0, 1, 2, 3 }; // incase it somehow breaks out of these loops
	}
}