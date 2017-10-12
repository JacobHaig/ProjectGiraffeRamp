#pragma once
#include "Person.h"
#include "Common.h"

namespace Movement {

	char getInput();
	bool move(char moveDir, vector<Person*> Entities, vector<string> curMap);
}
