#pragma once
#include "stdafx.h"
#include "Draw.h"
#include "Person.h"
#include "maps.h"
#include "Common.h"

namespace Fight 
{
	void fight(entSelect Entities, int entIndex, vector<int> playerStats, string statsFilename);
}