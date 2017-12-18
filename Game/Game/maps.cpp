#include "stdafx.h"
#include "Person.h"
#include "Maps.h"
#include "Utilities.h"
#include "Draw.h"
#include "Common.h"

using namespace std;

namespace Maps {
	vector<vector<string>> maps;

	// Returns the entire map that is selected
	vector<string> getMap(int index) {
		return maps[index];
	}

	// Returns the Charactor at a certain position
	char getCharPos(int selection, int x, int y) {
		return maps[selection][x][y];
	}

	// Inits the vectors of maps. Only do once!
	void initMaps() {
		string line;
		ifstream myfile("maps.txt");
		vector<string> wholeVector;

		// Read from the file
		while (getline(myfile, line))
			wholeVector.push_back(line);
		myfile.close();

		// Creates the maps
		for (int i = 0; i < wholeVector.size() / 33; i++) {
			vector<string> tempVector;
			for (int j = 2; j < 32; j++)
				tempVector.push_back(wholeVector[i * 33 + j]);
			maps.push_back(tempVector);
		}
	}
}


namespace Ents {
	auto createPerson(string name, int counterId, int x, int y) {
		Person *unit = new Person(name, counterId, x, y, "EnemyName");	//Creating the Objective/Enemy 
		return unit;										//(complex(dynamic) / does not go out of scope automatically / more control)
	}
	auto createPerson(string name, int counterId, COORD pos) {
		Person *unit = new Person(name, counterId, pos, "EnemyName");	//Creating the Objective/Enemy 
		return unit;										//(complex(dynamic) / does not go out of scope automatically / more control)
	}

	vector<vector<Person*>> ents;

	// Get the vector of ents selected
	vector<Person*> getEnt(int index) {
		return ents[index];
	}

	void changeEntsPos(entSelect selectedEnts, int entIndex, COORD pos) {
		ents[selectedEnts][entIndex]->setPos(pos);
	}

	// Start the ents vector
	void initEntities() {
		string line;
		ifstream myfile("ents.txt");
		vector<string> wholeVector;

		// Read the file
		while (getline(myfile, line))
			wholeVector.push_back(line);
		myfile.close();

		vector<vector<string>> entsVector;
		// Sort the file into the respective vector of strings
		for (int i = 0; i < wholeVector.size() / 15; i++) {
			vector<string> tempVector;
			for (int j = 2; j < 14; j++)
				tempVector.push_back(wholeVector[i * 15 + j]);
			entsVector.push_back(tempVector);
		}

		// Create the Person object from the vector of strings
		for (int i = 0; i < entsVector.size(); i++) {
			vector<Person*> tempVector;
			for (int j = 0; j < entsVector[i].size(); j++) {
				auto line = entsVector[i][j]; // Gives me the entire line

				string str = line.substr(1, 1);
				int pos1 = stoi(line.substr(4, 6));
				int pos2 = stoi(line.substr(7, 9));
				int pos3 = stoi(line.substr(10, 12));
				int pos4 = stoi(line.substr(13, 15));

				auto per = createPerson(str, j, Utilities::randPos(pos1, pos2, pos3, pos4));
				tempVector.push_back(per);
			}
			ents.push_back(tempVector);
		}
	}
}