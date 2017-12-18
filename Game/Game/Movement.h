#pragma once
#include "Person.h"
#include "maps.h"
#include "Common.h"

namespace Movement {

	char getInput();
	bool move(char key, entSelect entsSelected, int selection);
}
