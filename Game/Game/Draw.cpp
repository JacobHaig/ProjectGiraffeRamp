#include "stdafx.h"
#include "Draw.h"
#include "Utilities.h"
#include "Person.h"
#include "Maps.h"
#include "Common.h"



using namespace std;

namespace Draw {

	void drawEntities(vector<Person*> Entities, vector<string> Map) {
		for each (Person* P in Entities)
		{
			if (Map[P->getPosY()][P->getPosX()] == ' ') {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), P->Pos);
				cout << P->Name;
			}
		}
	}

	// drawMap function
	void drawMap(vector<string> Map) {//This is the "rendering" function

		for (short i = 0; i < Map.size(); i++)
		{
			for (short j = 0; j < Map[i].length(); j++)
			{

				COORD pos = { j ,i };
				char name = Map[i][j];

				if (name == '#') {
					name = char(219);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 | FOREGROUND_INTENSITY);
				}

				if (name == 'T' || name == 'h' || name == 'H')
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);

				if (name == '~' || name == '^')
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

				if (name == '+')
					name = char(92);

				if (name == 'A')
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

				if (name == '*')
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

				if (name != ' ') {
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					cout << name;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
			}
		}
	}

	void drawYourStats(vector<Person*> Ent1, vector<Person*> Ent2, vector<Person*> Ent3, vector<Person*> Ent4) {
		static int health = 100, mana = 100;
		int numOfEnt = 0;

		numOfEnt = Ent1.size() + Ent2.size() + Ent3.size() + Ent4.size();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 5 ,25 });
		cout << "Entities Left: " << numOfEnt;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 5 ,26 });
		cout << "Mana:   " << mana;
	}

	void drawFightStats(string yourName, string enemyName, int yourHealth, int enemyHealth) {

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 25 ,3 });// { x , y }
		cout << yourName;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 85,3 });
		cout << enemyName;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 7 ,25 });// { x , y }
		cout << "Skill 1: Placeholder";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 33 ,25 });// { x , y }
		cout << "Skill 2: Placeholder";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 7 ,27 });// { x , y }
		cout << "Skill 3: Placeholder";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 33 ,27 });// { x , y }
		cout << "Skill 4: Placeholder";

	}



	void drawMainMenu() {
		int speed = 50;//normal speed is 175
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

		COORD Pos = { 39,10 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << "Do you wish to ship the lore? (Y/N): ";
		char input;
		cin >> input;
		if (input == 'Y' || input == 'y')
			Draw::drawLore();

		//music.join();
		system("CLS");


	}

	void drawLore() {
		//thread music2(Utilities::PlayMusic, L"ThemeSong.wav");
		for (int i = 0; i < 35; i++)
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

		for each (string var in text)
		{
			cout << var << "\n";
			Sleep(450);
		}
		for (int i = 0; i < 35; i++)
		{
			cout << endl;
			Sleep(450);
		}
		//music2.join();   music2 must join if function is music2 is created or crash with occur 
		Sleep(100);
	}
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

		for each (string var in text)
		{
			cout << var << "\n";
			Sleep(time);
		}
		for (int i = 0; i < 35; i++)
		{
			cout << endl;
			Sleep(time);
		}
		//music2.join();   music2 must join if function is music2 is created or crash with occur 
		Sleep(100);
	}
}

