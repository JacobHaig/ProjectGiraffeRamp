#include "stdafx.h"
#include "SaveLoadGame.h"
#include "stdafx.h"
#include "Fight.h"
#include "Draw.h"
#include "Maps.h"
#include "Person.h"


#include <mmsystem.h>
#include <string>
#include <thread>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <Windows.h>
#include <cstdio>
#include <conio.h>

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
	vector<int> playerStatsLoadMain()
	{
		vector<int> playerStats;
		string statsFilename, str;
		int count = 0;
		COORD pos = { 48,11 };
		Draw::drawMap(Maps::saveMenu());
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

		do cin >> statsFilename;
		while (statsFilename.length() > 16 || statsFilename.length() < 0);
		statsFilename += ".txt";
		ifstream outputPlayerInfo(statsFilename);

		if (!outputPlayerInfo) { //if the file name doesn't exist  we need to make one
			outputPlayerInfo.close();
			ofstream createPlayerInfo(statsFilename);
			vector<int> defaults = SaveLoad::choosePlayerClass();//these may need to be changed
			for each(int i in defaults)
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
	void playerStatsLoad(vector<int> &playerStats, string statsFilename)
	{
		int count = 0;
		ifstream inputPlayerStats(statsFilename);

		while (count < 10 && inputPlayerStats >> playerStats[count])
			count++;
		inputPlayerStats.close();

	}

	//playerStatsSave function
	vector<int> playerStatsSave(vector<int> playerStats, string statsFilename, string playerName)
	{
		int count = 0;
		ofstream outputPlayerInfo(statsFilename);

		while (count <= 10 && outputPlayerInfo << playerStats[count])
			count++;
		outputPlayerInfo.close();

		return playerStats;
	}

	//npcStatsLoad function
	void npcStatsLoad(vector<double> &npcStats, vector<int> &playerStats)
	{
		//add NPCspell randomize pulling from spell file.
		int MAX_SPELL = 104, MIN_SPELL = 1, MAX_MULTI = 9, MIN_MULTI = 1, MAX_MULTIX = 5;
		unsigned seed = time(0);
		srand(seed);
		int npcUp, multiplierSeed, levelSeed, count = 0, infoSize = 10;
		double levelMultiplier, npcMultiplier;

		multiplierSeed = ((rand() % (MAX_MULTI - MIN_MULTI + 1)) + MIN_MULTI);
		static_cast<int>(levelSeed) = ((rand() % (MAX_MULTIX - MIN_MULTI + 1)) + MIN_MULTI);

		switch (multiplierSeed)
		{
		case 1: levelMultiplier = 0.900;
		case 2: levelMultiplier = 0.925;
		case 3: levelMultiplier = 0.950;
		case 4: levelMultiplier = 0.975;
		case 5: levelMultiplier = 1.000;
		case 6: levelMultiplier = 1.025;
		case 7: levelMultiplier = 1.050;
		case 8: levelMultiplier = 1.075;
		case 9: levelMultiplier = 1.100;
		}

		switch (levelSeed)
		{
		case 1: npcMultiplier = 0.250;
		case 2: npcMultiplier = 0.500;
		case 3: npcMultiplier = 1.000;
		case 4: npcMultiplier = 1.500;
		case 5: npcMultiplier = 2.000;
		}

		static_cast<int>(npcUp) = npcMultiplier * playerStats[5];

		npcStats[1] = static_cast<int>((playerStats[1] * .60) * levelMultiplier);
		npcStats[2] = static_cast<int>((playerStats[2] * .60) * levelMultiplier);
		npcStats[5] = static_cast<int>(playerStats[5] + npcUp);
		npcStats[0] = static_cast<int>(max(((playerStats[0] * .4) * (playerStats[5] * .4)), 1));
		npcStats[7] = static_cast<int>((rand() % (MAX_SPELL - MIN_SPELL + 1) + MIN_SPELL) - 1);

		if (npcStats[7] == npcStats[8])
			npcStats[8] = static_cast<int>((rand() % (MAX_SPELL - MIN_SPELL + 1)) + MIN_SPELL);
		if (npcStats[9] == npcStats[7] || npcStats[9] == npcStats[8])
			npcStats[9] = static_cast<int>((rand() % (MAX_SPELL - MIN_SPELL + 1)) + MIN_SPELL);

		
	}


	// choosePlayerClass function
	vector<int> choosePlayerClass()
	{
		int key, key2;
		COORD pos = { 20, 11 }; // { x , y } but has weird scaling
		COORD pos2 = { 48 , 13 };
		string resetMessage = "Input incorrect, please try again!";

		system("CLS");
		//Draw::drawMap(Maps::classSelect());
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << "Press 1 for FireMage, 2 for WaterMage, 3 for EarthMage, 4 for WindMage...";

		do
		{
			do
			{
				key = _getch();
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
				cout << "Press again to confirm...";
				key2 = _getch();

				if (key == key2)
					switch (key)
					{
					case 49: return{ 15,3,8,0,1,1,0,0,1,2,3 }; //return vector<int> playerStats
					case 50: return{ 15,3,8,0,2,1,0,78,79,80,81 };
					case 51: return{ 15,3,8,0,3,1,0,26,27,28,29 };
					case 52: return{ 15,3,8,0,4,1,0,52,53,54,55 };
					}
				if (key != key2)
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
				cout << resetMessage;
			} while (key != 49 || key != 50 || key != 51 || key != 52);

		} while (key != key2);

	}

}