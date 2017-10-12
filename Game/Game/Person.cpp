#include "stdafx.h"
#include "Person.h"
#include "Common.h"
using namespace std;

Person::Person(string name, int id, int x, int y, string realname)
{
	Id = id;
	RealName = realname;
	Name = name;
	Pos.X = x;
	Pos.Y = y;
}
Person::Person(string name, int id, COORD pos, string realname)
{
	Id = id;
	Name = name;
	RealName = realname;
	Pos.X = pos.X;
	Pos.Y = pos.Y;
}
// posibly set enemy here?
// 0 = HP, 1 = ARM, 2 = ATK, 3 = ENG, 4 = ELM, 5 = LEVEL


void Person::SetInfo(int x, int y)
{
	Pos.X = x;
	Pos.Y = y;
}
void Person::moveX(int x) {
	SetInfo(Pos.X + x, Pos.Y);
}
void Person::moveY(int y) {
	SetInfo(Pos.X, Pos.Y + y);
}
int Person::getPosX() {
	return Pos.X;
}
int Person::getPosY() {
	return Pos.Y;
}
COORD Person::getPos() {
	return Pos;
}
void Person::setPos(COORD pos) {
	Pos = pos;
}