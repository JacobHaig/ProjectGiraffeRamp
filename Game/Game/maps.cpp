#include "stdafx.h"
#include "Person.h"
#include "Maps.h"
#include "Utilities.h"
#include "Draw.h"
#include "Common.h"

using namespace std;


namespace Maps {
	auto createPerson(string name, int counterId, int x, int y) {
		Person *unit = new Person(name, counterId, x, y, "EnemyName");   //Creating the Objective/Enemy 
		return unit;										//(complex(dynamic) / does not go out of scope automatically / more control)
	}
	auto createPerson(string name, int counterId, COORD pos) {
		Person *unit = new Person(name, counterId, pos, "EnemyName");   //Creating the Objective/Enemy 
		return unit;										//(complex(dynamic) / does not go out of scope automatically / more control)
	}

	vector<vector<string>> maps;

	vector<string> getMap(int index) {
		return maps[index];
	}
	char getCharPos(int selection, int x, int y) {
		return maps[selection][x][y];
	}

	void initMaps() {

		string line;
		ifstream myfile("maps.txt");
		vector<string> wholeVector;

		while (getline(myfile, line))
			wholeVector.push_back(line);
		myfile.close();


		for (int i = 0; i < wholeVector.size() / 33; i++) {
			vector<string> tempVector;
			for (int j = 2; j < 32; j++) {
				tempVector.push_back(wholeVector[i * 33 + j]);
			}
			maps.push_back(tempVector);
		}

		
	}

	vector<string> saveMenu()
	{
		vector<string> Save = {
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                               ------------------------------------------------------                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               |          Please enter the save file name           |                                    \n" },
			{ "                               |             ----Max 16 Characters----              |                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               ------------------------------------------------------                                    \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
		};
		return Save;
	};

	vector<string> playerInfo() { // returns Map1 
		vector<string> menu = {
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "######################################################################################################################## \n" },
			{ "###                                                      ######                                                      ### \n" },
			{ "###                                                      ######                                                      ### \n" },
			{ "###                                                      ######                                                      ### \n" },
			{ "###                                                      ######                                                      ### \n" },
			{ "######################################################################################################################## \n" },
			{ "######################################################################################################################## " }
		};
		return menu;
	}

	vector<Person*> Entities1() {
		vector<Person*> Entities;
		int counterId = 1;

		Entities.push_back(createPerson(" ", counterId++, 0, 0));
		Entities.push_back(createPerson("@", counterId++, Utilities::randPos(1, 15, 1, 15)));
		Entities.push_back(createPerson("#", counterId++, Utilities::randPos(5, 10, 5, 7)));
		Entities.push_back(createPerson("$", counterId++, Utilities::randPos(5, 35, 4, 9)));
		Entities.push_back(createPerson("%", counterId++, Utilities::randPos(5, 9, 5, 6)));
		Entities.push_back(createPerson("!", counterId++, Utilities::randPos(4, 36, 5, 4)));
		Entities.push_back(createPerson("(", counterId++, Utilities::randPos(5, 24, 5, 8)));
		Entities.push_back(createPerson("~", counterId++, Utilities::randPos(5, 30, 5, 13)));
		Entities.push_back(createPerson(")", counterId++, Utilities::randPos(8, 80, 5, 10)));
		Entities.push_back(createPerson("-", counterId++, Utilities::randPos(5, 75, 5, 13)));

		Entities.push_back(createPerson(")", counterId++, Utilities::randPos(6, 60, 2, 15)));
		Entities.push_back(createPerson("+", counterId++, Utilities::randPos(5, 75, 5, 5)));
		return Entities;
	}
	vector<Person*> Entities2() {
		vector<Person*> Entities;
		int counterId = 1;

		Entities.push_back(createPerson(" ", counterId++, 0, 0));
		Entities.push_back(createPerson("@", counterId++, 15, 15));
		Entities.push_back(createPerson("#", counterId++, 10, 11));
		Entities.push_back(createPerson("$", counterId++, 35, 9));
		Entities.push_back(createPerson("%", counterId++, 19, 6));
		Entities.push_back(createPerson("!", counterId++, 26, 4));
		return Entities;
	}
	vector<Person*> Entities3() {
		vector<Person*> Entities;
		int counterId = 1;

		Entities.push_back(createPerson(" ", counterId++, 0, 0));
		Entities.push_back(createPerson("@", counterId++, 15, 15));
		Entities.push_back(createPerson("#", counterId++, 10, 11));
		Entities.push_back(createPerson("$", counterId++, 35, 9));
		Entities.push_back(createPerson("%", counterId++, 19, 6));
		Entities.push_back(createPerson("!", counterId++, 26, 4));
		return Entities;
	}
	vector<Person*> Entities4() {
		vector<Person*> Entities;
		int counterId = 1;

		Entities.push_back(createPerson(" ", counterId++, 0, 0));
		Entities.push_back(createPerson("@", counterId++, 15, 15));
		Entities.push_back(createPerson("#", counterId++, 10, 11));
		Entities.push_back(createPerson("$", counterId++, 35, 9));
		Entities.push_back(createPerson("%", counterId++, 19, 6));
		Entities.push_back(createPerson("!", counterId++, 26, 4));
		return Entities;
	}

	vector<string> pauseMenu() { // returns Map1 
		vector<string> Map = {
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                               ------------------------------------------------------                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               |               The Game is Now Paused               |                                    \n" },
			{ "                               |              ------------------------              |                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               |               Press esc to continue                |                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               |                                                    |                                    \n" },
			{ "                               ------------------------------------------------------                                    \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
		};
		return Map;
	}

	vector<string> Map1() { // returns Map1 
		vector<string> Map = {
			{ "######################################################################################################################## \n" },
			{ "######################################################################################################################## \n" },
			{ "###AA      TTTTTTTTTTT      AA      TTTTTTTTTTT      AA                                                       AAA    ### \n" },
			{ "###AA      T         T      AA      T         T      AA                                                      AAAAA   ### \n" },
			{ "###AA      T         T      AA      T         T      AA                             AAAAAAAAAAA               AAA    ### \n" },
			{ "###AA      T         T      AA      T         T      AA                         AAAAAAAAAAAAAAAAAAA                  ### \n" },
			{ "###AA      T         T      AA      T         T      AA                       AAAAAAAAAAAAAAAAAAAAAAA                ### \n" },
			{ "###AA      TTTTT TTTTT      AA      TTTTT TTTTT      AA                         AAAAAAAAAAAAAAAAAAA                  ### \n" },
			{ "###                                                                                 AAAAAAAAAAA                      ### \n" },
			{ "###                                                                                                                  ### \n" },
			{ "###                                                                                                                   *  \n" },
			{ "###                                                                                                                   *  \n" },
			{ "###                                                                                                                   *  \n" },
			{ "###                                                                                                                  ### \n" },
			{ "###   TTTTTTTT   TTTTTTTT                                                          ~~^~~~^~~~^~                      ### \n" },
			{ "###   T                 T                                           ~~~^~~~^~~~^~~~~~^~~~~~^~~~^~~^~~~^~~~           ### \n" },
			{ "###   T     --- ---     T                                 ~^~~^~~~~^~~~^~~^~~^~~~~^~~~~^~~~^~~~~~^~~~~^~~~~~^~~~^~~^~### \n" },
			{ "###   T    |       |    T                            ~~~^~~^~~~~^~~~^~~^~~^~~~~^~~~~^~~~~~~^~~^~~~~^~~~^~~^~~^~~~~^~~### \n" },
			{ "###   T     -------     T                         ~~^~~~~^~~~~^~~~~~~^~~^~~~~^~~~^~~~~^~~~~^~~~^~~^~~^~~~~^~~~~^~~~~~### \n" },
			{ "###   TTTTTTTTTTTTTTTTTTT                          ~~~^~~^~~~~^~~^~~~~^~~^~~~~^~~~^~~~~^~~~~^~~~~~~^~~^~~~~^~~~^~~^~~### \n" },
			{ "###                                                     ~~~~^~~~~^~~~~~~^~~^~~~~^~~~^~~^~~~~~~^~~~~~^~~~~^~~~^~~~^~~~### \n" },
			{ "##########################################      ######################################################################## \n" },
			{ "##########################################******######################################################################## \n" }
		};
		return Map;
	}
	vector<string> Map2() { // returns Map2 
		vector<string> Map = {
			{ "##########################################******######################################################################## \n" },
			{ "##########################################      ######################################################################## \n" },
			{ "###TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT      T                      ~~~^~~~~^~~~~~~^~~^~~~~^~~~^~^~~~~^~~~~~~^~~^~### \n" },
			{ "###T T                  T                       T       T      T                        ~~~^~~~~^~~~^~~~~~^~~~~^~~~^~### \n" },
			{ "###T TTTTTT TTTTTTTTTTTTTT TTTTTTTTTTTTTTTTTTTTTT       TTTTT TT                                              ~^~^~~~### \n" },
			{ "###                                  T                                                                               ### \n" },
			{ "###TTTTTTTTTTTTTTTTTT TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT TTTTTTTTTTTTTTTTTTTTTT                                    ### \n" },
			{ "###                   T       T                         T             T         T                                    ### \n" },
			{ "###TTTTTTTT TTTTTTTTTTTTTT TTTTTTTT TTTTTTTTTTTTTTTTTTT TTTTT TTTTTTTTTTTTTTTTT TTTTTTTTTTTTTTTTTTTTTTTT             ### \n" },
			{ "###                         T              T          T T                                     T        TTTTTTTTTTTT  ### \n" },
			{ "### TTTTTTTTTTTTTTTTTTTTTTTTTTTT TTTTTTTTT T TTTTTTTTTT TTTTTTTTTTTTTTTTTTTTTTTTTTTTT                             T   *  \n" },
			{ "###         T                  T T                            T             T         TTTTTTTTTTTTTTTTTTTTT TTTTTTT   *  \n" },
			{ "###       T TTTTTTTT T TTTTTTTTT TTTTTTTTTTTTTTTTTTTT       TTTTT  T T TTTTTTTT                                   T   *  \n" },
			{ "### TTTTTTTTT        T         T T                                 T T      TTTTTTTTTTTTTTTTTTTTTTTTTTTTT       TTTTT### \n" },
			{ "### T                TTTTTTTTTTT TTTTTTTTTTTTTT TTTTTTTTTTTTTTTT   T T            T                                  ### \n" },
			{ "### TTTTTTTTTTTTTTTTTT                                             T TTTTTTTTTTTTTTTTTTT               TTTTTTTTTTTTTT### \n" },
			{ "### T            TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT         T       T                   T                             ### \n" },
			{ "###       TTTT                                       T     T       TTTTTTTTTTTTTTTTTTT TT TTTTTTTTTTTTTTTTTTTT       ### \n" },
			{ "###TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT        TTTT     TTTTT         T             T                     T       ### \n" },
			{ "###T                                                 T     T       TTTTT TTTTT TTTTTTTTTTT TTTTTTTTTTT TTTTTTT       ### \n" },
			{ "###TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT                           T                     ### \n" },
			{ "######################################################################################################################## \n" },
			{ "######################################################################################################################## \n" }
		};
		return Map;
	}
	vector<string> Map3() { // returns Map3
		vector<string> Map = {
			{ "######################################################################################################################## \n" },
			{ "######################################################################################################################## \n" },
			{ "###                                                                          __         /+_                          ### \n" },
			{ "###                                                                         /  +_     _/   +         __              ### \n" },
			{ "###                                                                      __/     +  ~/      +       /  +             ### \n" },
			{ "###                                                                    _/         +~/        +__   /    +     _      ### \n" },
			{ "###                                                                   / ___       ~/   _        + /      +_  / +_    ### \n" },
			{ "###                                                                  / /   +_    ~/   / +      _ +         +/    +  _### \n" },
			{ "###                                                                 / /      + ~~/  _/   +    / + +         +__   +/ ### \n" },
			{ "###                                                                  /--_-----~~/  /      +_ /   + +_    _/+  _+  /  ### \n" },
			{ " *                                                                           ~~/- /         +  /+_+  +  /   +/  +/   ### \n" },
			{ " *                                                                         ~~~   /---__--_---+/---++_-+/--_--+---+---### \n" },
			{ " *                                                                   ~^~^~~~                                         ### \n" },
			{ "###                                                              ~^~~^~~^~                                           ### \n" },
			{ "###                                                   H  H~~^~^~~~^~^~                                               ### \n" },
			{ "###                                       ~~~^~~~^~^~^~H  H~^~~^~~~                                                  ### \n" },
			{ "###                                 ~^~~^~~~^~^~^~~^~~  H  H                                                         ### \n" },
			{ "###~~~^~~~^~~~^~~^~^~^~^~~^~~~^~~^~^~^~~~^~~~^~~                                                                     ### \n" },
			{ "###~~^~~~^~~~^~~~^~~~^~~~^~~^~~~^~~^~~~^~                              AAAAAAA                                       ### \n" },
			{ "###~~^~~^~~~^~~^~~^~~^~~^~~^~^~~^~~^~                   AAAA      AAAAAAAAAAAAAAAAAAA                                ### \n" },
			{ "###~~~^~~^~~~^~~^~^~~^~^~~^~~~^~~~                 AAAAAAAAA      AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA### \n" },
			{ "############################################################      ###################################################### \n" },
			{ "############################################################******###################################################### \n" }
		};
		return Map;
	}
	vector<string> Map4() { // returns Map4
		vector<string> Map = {
			{ "##########################################################******######################################################## \n" },
			{ "##########################################################      ######################################################## \n" },
			{ "###~^~^~~~~~^~^~~~^~^~^   __/               AAAAAAAAAAAAA        AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA### \n" },
			{ "###~~~~^~~~^~^~^~~^~                      AAAAAAAAAAAA             AAAAAAAAAAAAAAAAAA                AAAAAAAAAAAAAAAA### \n" },
			{ "###~~^~~^~~^~~^~           __/              AAAAAAAA                 AAAAAAAA                            AAAAAAAAAAAA### \n" },
			{ "###                                            AAAAAA        A        AAAAAAAAAA                            AAAAAAAAA### \n" },
			{ "###             h TT                             AA         AAA         AAAA            A              A      AAAAAAA### \n" },
			{ "###                             AAAAA                     AAAAAAA        AA            AAA           AAAA       AAAAA### \n" },
			{ "###                           AAAAAAAAA                     AAAAAAA                   AAAAA         AAAAAAA       AAA### \n" },
			{ "###AAAAAAAAAAAAAAAAA       AAAAAAAAAA                        AAAAAAAAA              AAAAAAAAAA        AAA          AA### \n" },
			{ " *      AAAAAAAAAAAAAAAAAAAAAAAA                                AAAA                 AAAAAAAAAAA                    A### \n" },
			{ " *           AAAAAAAAAAAAAA                                      A                     AAAAAAAAAAA                   ### \n" },
			{ " *              AAAAAA                                    AAAA               AAA        AAAAAAAAA                    ### \n" },
			{ "###                        AAAAA                         AAAAAAAAAAA       AAAAAAAA        AAA           AAA        A### \n" },
			{ "###                      AAAAAAAAAAA                   AAAAAAAA             AAAAAAAAAAA                 AAAAA       A### \n" },
			{ "###                    AAAAA      AAAAAAA               AAAAAA                AAAAAAAAAAA           AAAAAA         AA### \n" },
			{ "###          A        AAAAA                               AAA         A         AAAAAAA           AAAA          AAAAA### \n" },
			{ "###         AAA         AAAA                               A         AAA           AA          AAAAA         AAAAAAAA### \n" },
			{ "###          AAA          AAAAAAA                     A             AAAAAA                AAAAAA           AAAAAAAAAA### \n" },
			{ "###           A                                     AAAAA          AAAAAAAAAA                         AAAAAAAAAAAAAAA### \n" },
			{ "###                                              AAAAAAAAAAAA       AAAAAAAAAAAA                   AAAAAAAAAAAAAAAAAA### \n" },
			{ "######################################################################################################################## \n" },
			{ "######################################################################################################################## \n" }
		};
		return Map;
	}

}