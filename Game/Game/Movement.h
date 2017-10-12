#include "Person.h"
#include <vector>
#pragma once
namespace Movement {

	char getInput();
	bool move(char moveDir, vector<Person*> Entities, vector<string> curMap);
}
