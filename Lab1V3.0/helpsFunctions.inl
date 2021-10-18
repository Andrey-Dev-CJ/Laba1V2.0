#pragma once
#include"helpsFunctions.h"
#include<string>
using namespace std;

template <class T>
void inputMy(T& m) {
	
	string text(" ");
	int sz = sizeof(T);
	if (sz == 4)
		text = " integer number";

	while (cin.fail()) {
		cin.clear();
		cin.ignore();
	
		cout << "Enter" << text <<" - ";
		cin >> m;
	}
}
