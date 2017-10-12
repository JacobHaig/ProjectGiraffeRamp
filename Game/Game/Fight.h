#pragma once
#include "stdafx.h"
#include "Draw.h"
#include "Person.h"
#include "Common.h"

namespace Fight 
{
	void fight(vector<Person*> Entities, string OppenentName,string yourName, vector<int> playerStats, string statsFilename);
}

