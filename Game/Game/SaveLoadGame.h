#pragma once
#include "stdafx.h"
#include "Fight.h"
#include "Draw.h"
#include "Person.h"
#include "Common.h"


enum stats
{
	HP = 0, ARM, ATK, ENG, ELM, LEVEL, Name, Skill1, Skill2, Skill3, Skill4
};

/*
TO DO:

FUNCTIONS:
playerStatsLoad : loads the players stats to the playerStats integer and returns playerStats
playerInfoLoad : loads the players information to the playerInfo string and returns playerInfo
npcStatsLoad : loads the npcs stats to the npcStats integer and returns npcStats
npcInfoLoad : loads the npcs info to the npcInfo string and returns npcInfo

PRIMARY VARIABLES:
playerStats : 0 = HP, 1 = ARM, 2 = ATK, 3 = ENG, 4 = ELM, 5 = LEVEL, 6 = Name, 7 = Skill1, 8 = Skill2, 9 = Skill3, 10 = Skill4
npcStats : 0 = HP, 1 = ARM, 2 = ATK, 3 = ENG, 4 = ELM, 5 = LEVEL, 6 = Name, 7 = Skill1, 8 = Skill2, 9 = Skill3
*/

namespace SaveLoad
{
	vector<int> playerStatsLoadMain();
	void playerStatsLoad(vector<int> &playerStats, string statsFilename);
	vector<int> playerStatsSave(vector<int> playerStats, string statsFilename, string playerName);
	void npcStatsLoad(vector<double>  &npcStats, vector<int> &playerStats);
	vector<int> choosePlayerClass();
}