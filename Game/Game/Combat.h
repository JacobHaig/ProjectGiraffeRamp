#pragma once
#include "stdafx.h"
#include "Fight.h"
#include "Draw.h"
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
playerStats : 0 = HP, 1 = ARM, 2 = ATK, 3 = ENG, 4 = ELM, 5 = LEVEL
npcStats : 0 = HP, 1 = ARM, 2 = ATK, 3 = ENG, 4 = ELM, 5 = LEVEL
playerInfo : 0 = Name, 1 = Skill1, 2 = Skill2, 3 = Skill3, 4 = Skill4
npcInfo : 0 = Name, 1 = Skill1, 2 = Skill2, 3 = Skill3
playerMultiplier = represents player damage multiplier for attacks
*/

//Begin combatDraw function
//Draw skill menu and combat box

//optimally 4-6 skills, at the bottom of the screen
//pulls skills from player save file
//Draw player image (default image or possibly sex based)
//Draw NPC image
//use npc identifier to select from designed images
//load selected npc image 
//End Draw combat elements function


int attack(int playerStats[6], int npcStats[6], double effectiveSkill)
{
	//Begin Attack function
	//pulls data from selected player skill. key values (effectiveSkill - determines the multipler of the skills damage, pulled from the skills data)
	int totalDamage = getDamage(playerStats[4], npcStats[4], playerStats[2], npcStats[1], effectiveSkill);

	//Display player attack animation
	//Damage is resolved
	npcStats[0] -= totalDamage;
	return (npcStats[0]);
}

int npcAttack(int npcStats[], int playerStats[], double effectiveSkill)
{
	//Begin Attack function
	//pulls data from selected player skill. key values (effectiveSkill - determines the multipler of the skills damage, pulled from the skills data)
	int totalDamage = getDamage(npcStats[4], playerStats[4], playerStats[2], npcStats[1], effectiveSkill);

	//Display player attack animation
	//Damage is resolved
	playerStats[0] -= totalDamage;
	return (playerStats[0]);
}

int getDamage(int Stats1, int Stats2, int Stats3, int Stats4, int Skill)
{
	if (Stats1 == 1) {
		if (Stats2 == 1)
			return (Stats3 - Stats4);
		if (Stats2 == 2)
			return (Stats3 * Skill - Stats4);
		if (Stats2 == 3)
			return (Stats3 - Stats4);
		if (Stats2 == 4)
			return (Stats3 * 0.5);
	}
	if (Stats1 == 2) {
		if (Stats2 == 1)
			return (Stats3 * 0.5);
		if (Stats2 == 2)
			return (Stats3 - Stats4);
		if (Stats2 == 3)
			return (Stats3 * Skill - Stats4);
		if (Stats2 == 4)
			return (Stats3 - Stats4);
	}
	if (Stats1 == 3) {
		if (Stats2 == 1)
			return (Stats3 - Stats4);
		if (Stats2 == 2)
			return (Stats3 * 0.5);
		if (Stats2 == 3)
			return (Stats3 - Stats4);
		if (Stats2 == 4)
			return (Stats3 * Skill - Stats4);
	}
	if (Stats1 == 4) {
		if (Stats2 == 1)
			return (Stats3 * Skill - Stats4);
		if (Stats2 == 2)
			return (Stats3 - Stats4);
		if (Stats2 == 3)
			return (Stats3 * 0.5);
		if (Stats2 == 4)
			return (Stats3 - Stats4);
	}
}

void endCombat()
{
	//Draw end combat menu

	//Show NPC skills, player skills, input prompt
	//save changes to playerSave
	//end end combat menu
}


bool gameOver()
{

}
