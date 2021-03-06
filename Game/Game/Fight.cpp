#include "stdafx.h"
#include "Fight.h"
#include "GameCombat.h"
#include "SaveLoadGame.h"

//Create a combat header file for attack commands and interaction with entities.

namespace Fight
{
	void fight(entSelect Entities, int entIndex, vector<int> playerStats, string statsFilename)
	{
		auto ents = Ents::getEnt(Entities);
		string OppenentName = ents[entIndex]->RealName;

		string yourName = "Gary 25";

		bool playerDead = false, npcDead = false;				//Declare player stats, enemy stats, named attacks
		int skillMultiplier = 1;
		vector<double> npcStats(10) /*,playerStats*/;

		SaveLoad::playerStatsLoad(playerStats, statsFilename);	//Load player data from save file, pull npc data from npc function
		SaveLoad::npcStatsLoad(npcStats, playerStats);
		GameCombat::drawFight(playerStats, npcStats);			//must be out side of loop unless you want it to flickering 

		while (playerDead == false && npcDead == false)
		{
			Draw::drawFightStats(yourName, OppenentName, 10, 9001);
			GameCombat::attack(playerStats, npcStats, skillMultiplier);
			GameCombat::getInput();								//get input from charactor

			if (npcStats[0] <= 0)
				GameCombat::npcAttack(npcStats, playerStats, skillMultiplier);
			else
			{
				Draw::drawVectorMaps(mapSelect::fightScreen);
				GameCombat::selectPrompt(playerStats);
			}

			if (playerStats[0] <= 0 /*? true : false*/)
				continue;
			else
				GameCombat::gameOver();
		}
	}
}