#pragma once
#include <string>
#include <fstream>
#include<iostream>
#include"List.h"


using namespace std;

class Ship
{

public:

	virtual void save()=0;
	//virtual void recovery() = 0;
	virtual void print() = 0;
	virtual void init()= 0;


};

