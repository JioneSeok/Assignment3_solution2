#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class File {
public:
	File() {};
	int n1, n2;
	float a, b, x, dx, m;

	void fileOpen(string s) {
		ifstream xx;
		xx.open("s", ios::binary | ios::in);
		xx >> n1 >> n2 >> a >> b >> x >> dx >> m;
	}
};