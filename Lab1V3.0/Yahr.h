#pragma once
#include "Ship.h"
#include "helpsFunctions.h"

using namespace std;

class Ship;
class Yaht :
	public Ship
{
private:
	char type[80];
	char name[80];
	char mission[80];
	int speedMax;
	int length;
	int crew;
public:
	void save();
	void print();
	void init();
	explicit Yaht();
	Yaht(string str);
	Yaht(char*type,char*name,char*mission ,int speedMax, int length, int crew);
	Yaht(int fl);
	Yaht(const Yaht& other);

};

