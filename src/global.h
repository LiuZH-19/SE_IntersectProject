#ifndef GLOBAL_H_
#define GLOBAL_H_
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#define EPS  0.0000001

struct Line {
	double A;
	double B;
	double C;
	Line() :A(0), B(0), C(0) {};
	Line(double x1, double y1, double x2, double y2) {
		A = y1 - y2;
		B = x2 - x1;
		C = x1 * y2 - x2 * y1;
	}
};

struct Circle {
	double X;
	double Y;
	double R;
	Circle() :X(0), Y(0), R(0) {};
	Circle(double x, double y, double r) {
		X = x;
		Y = y;
		R = r;
	}
};

int dcmp(double x);



#endif // !GLOBAL_H_

