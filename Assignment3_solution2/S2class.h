#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class ST {
public:
	ST() {};
	ST(int nn1, int nn2, float aa, float bb, float xx, float ddx, float mm) {
		n1 = nn1;
		n2 = nn2;
		a = aa;
		b = bb;
		x = xx;
		dx = ddx;
		m = mm;
	}

	int n1, n2;
	float a, b, x, dx, m;
	int sum;
	int* sum1;
	float* sum2;
	string s;

	void f1() {
		sum1 = new int[n2 - n1 + 1];
		for (int i = n1; i < n2; i++) {
			sum = 0;
			for (int j = 0; j < n2 - n1 + 1; j++) {
				sum += j;
			}
			sum1[i - n1] = sum;
		}
	}

	void newFile() {
		sum2 = new float[m];
		for (int i = 0; i < m; i++) {
			sum2[i] = a * x + b;
			x += dx;
		}
	}
	void inFile() {
		f1();
		newFile();

		if (n1 == 5) {
			s = "akali.dat";
		}
		else if (n1 == 7) {
			s = "amumu.dat";
		}
		else if (n1 == 12) {
			s = "annie.dat";
		}
		else if (n1 == 10) {
			s = "ashe.dat";
		}

		ofstream xx;
		xx.open(s, ios::binary | ios::out);
		xx << n1 << n2 << a << b << x << dx << m;
		xx.write((char*)sum1, sizeof(sum1));
		xx.write((char*)sum2, sizeof(sum2));
		xx.close();
	}
	void delFile() {
		inFile();
		delete[]sum1;
		delete[]sum2;
	}
};