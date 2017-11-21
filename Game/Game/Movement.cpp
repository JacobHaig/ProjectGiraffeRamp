#include "stdafx.h"
#include "Person.h"
#include "Movement.h"
#include "Draw.h"
#include "Utilities.h"
#include "Maps.h"

#include "Common.h"

#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27


namespace Movement {

	char getInput() {
		char key = _getch();
		return key;
	}

	bool move(char key, vector<Person*> Entities,int selection) {

		switch (key)
		{
		case KEY_ESC:
			system("CLS");
			Draw::drawVectorMaps(mapSelect::pauseMenu);
			while (_getch() != KEY_ESC) {}
			system("CLS");
			Draw::drawVectorMaps(selection);
			return false;

		case KEY_W: // Player 1
			Entities[Utilities::vectorObjIndex("@", Entities)]->moveY(-1);
			return true;
		case KEY_A:
			Entities[Utilities::vectorObjIndex("@", Entities)]->moveX(-1);
			return true;
		case KEY_S:
			Entities[Utilities::vectorObjIndex("@", Entities)]->moveY(1);
			return true;
		case KEY_D:
			Entities[Utilities::vectorObjIndex("@", Entities)]->moveX(1);
			return true;
		default:
			return false;
		}
	}
}