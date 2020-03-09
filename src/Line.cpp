#include "Line.h"

using namespace std;

Line::Line(double x1, double y1, double x2, double y2)
{
	A = y1 - y2;
	B = x2 - x1;
	C = x1*y2 - x2*y1;
}

double Line::getA()
{
	return A;
}

double Line::getB()
{
	return B;
}

double Line::getC()
{
	return C;
}
/*
bool Line:: operator < (const Line& l) const 
{
	bool result = true;
	if (A == l.A && B == l.B && C = l.C) {
		result = false;
	}
	return result;
}
*/

