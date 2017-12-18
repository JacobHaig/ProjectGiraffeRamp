#include "stdafx.h"
#include "Draw.h"
#include "Utilities.h"
#include "Person.h"
#include "Maps.h"
#include "Common.h"

using namespace std;

namespace Draw {

	// Draws all ents at their locations
	void drawVectorEntities(int entSelected, int mapSelection) {
		auto map = Maps::getMap(mapSelection);
		auto ents = Ents::getEnt(entSelected);
		for each (Person* P in ents)
			if (map[P->getPosY()][P->getPosX()] == ' ') {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), P->Pos);
				cout << P->Name;
			}

	}

	// Draws the entire vector of maps that is selected
	void drawVectorMaps(int selection) {
		auto map = Maps::getMap(selection); // Get the map

		for (int i = 0; i < map.size(); i++)
			for (int j = 0; j < map[i].length(); j++) {
				char charactor = map[i][j];
				if (charactor != ' ') {
					changeCursorProperties(i, j, charactor);
					std::cout << charactor;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
			}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

	}

	// Depending on what charactor is selected from the map we need to change the color
	void changeCursorProperties(int i, int j, char &charactor) {
		COORD pos = { j, i };

		if (charactor != ' ')  // Changing the posistion takes time. Lets only do it when needed!
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

		if (charactor == '#') {
			charactor = char(219);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 | FOREGROUND_INTENSITY);
		}

		if (charactor == 'T' || charactor == 'h' || charactor == 'H')
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);

		if (charactor == '~' || charactor == '^')
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

		if (charactor == '+')
			charactor = char(92);

		if (charactor == 'A')
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

		if (charactor == '*')
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

	}

	// drawYourStats
	void drawYourStats() {
		static int health = 100, mana = 100;
		vector<vector<Person*>> entsVect;
		for (int i = 0; i < 4; i++)
			entsVect.push_back(Ents::getEnt(i));
		int numOfEnt = entsVect[0].size() + entsVect[1].size() + entsVect[2].size() + entsVect[3].size();

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 5, 25 });
		cout << "Entities Left: " << numOfEnt;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 5, 26 });
		cout << "Mana:   " << mana;
	}

	// drawFightStats
	void drawFightStats(string yourName, string enemyName, int yourHealth, int enemyHealth) {

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 25, 3 });	// { x , y }
		cout << yourName;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 85, 3 });
		cout << enemyName;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 7, 25 });
		cout << "Skill 1: Placeholder";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 33, 25 });
		cout << "Skill 2: Placeholder";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 7, 27 });
		cout << "Skill 3: Placeholder";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 33, 27 });
		cout << "Skill 4: Placeholder";

	}

	// drawMainMenu
	void drawMainMenu() {
		int speed = 150;	//normal speed is 175
		//thread music(Utilities::PlayMusic, L"ThemeSong.wav");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		for (int i = 0; i < 35; i++)
			cout << endl;

		ifstream titleFile("TitleOfGame.txt");
		string str;
		vector<string> text;

		while (std::getline(titleFile, str))
			text.push_back(str);

		titleFile.close();
		for each (string var in text)
		{
			cout << var << "\n";
			Sleep(speed);
		}
		for (int i = 0; i < 35; i++)
		{
			cout << endl;
			Sleep(speed);
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("CLS");
		Sleep(750);

		COORD Pos = { 39, 10 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << "Do you wish to ship the lore? (Y/N): ";
		char input;
		cin >> input;
		if (input == 'Y' || input == 'y')
			Draw::drawLore();

		//music.join();
		system("CLS");
	}

	// This is depercated. we will no long draw lore
	void drawLore() {
		//thread music2(Utilities::PlayMusic, L"ThemeSong.wav");

		/*for (int i = 0; i < 35; i++)
			cout << endl;

		ifstream titleFile("Lores.txt");
		string str;
		vector<string> text;
		while (std::getline(titleFile, str))
			text.push_back(str);

		titleFile.close();
		system("CLS");
		cout << "ji";
		for (int i = 0; i < 35; i++)
			cout << endl;

		for each (string var in text) {
			cout << var << "\n";
			Sleep(450);
		}
		for (int i = 0; i < 35; i++) {
			cout << endl;
			Sleep(450);
		}*/

		//music2.join();   music2 must join if function is music2 is created or crash with occur 
		Sleep(100);
	}

	// end of game credits scene
	void drawCredits() {
		//thread music2(Utilities::PlayMusic, L"ThemeSong.wav");
		int time = 200;
		for (int i = 0; i < 35; i++)
			cout << endl;

		ifstream titleFile("Credits.txt");
		string str;
		vector<string> text;
		while (std::getline(titleFile, str))
			text.push_back(str);
		titleFile.close();

		system("CLS");

		for (int i = 0; i < 35; i++)
			cout << endl;

		for each (string var in text) {
			cout << var << "\n";
			Sleep(time);
		}

		for (int i = 0; i < 35; i++) {
			cout << endl;
			Sleep(time);
		}
		//music2.join();   music2 must join if function is music2 is created or crash with occur 
		Sleep(100);

	}
}

