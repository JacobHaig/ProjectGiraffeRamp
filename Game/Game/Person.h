#pragma once
#include "Common.h"

using namespace std;

class Person
{
public:
	COORD Pos;
	string Name;
	string RealName;
	string Id;
	double health;

	Person(string Name, int id, int x, int y,string realname);
	Person(string name, int id, COORD pos, string realname);
	void SetInfo(int X, int Y);
	void moveX(int x);
	void moveY(int y);
	int getPosX();
	int getPosY();
	COORD getPos();
	void setPos(COORD pos);
};

