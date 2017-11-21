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
			for (int j = 2; j < 32; j++) 
				tempVector.push_back(wholeVector[i * 33 + j]);
			
			maps.push_back(tempVector);
		}
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
}