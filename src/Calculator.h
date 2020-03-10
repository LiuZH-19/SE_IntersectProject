#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "global.h"
#include "Point.h"

using namespace std;

class Calculator
{
public:
	Calculator();
	int haveIntersection(Line l1, Line l2, set<Point>& nodeSet);
	int haveIntersection(Circle c, Line l, set<Point>& nodeSet);
	int haveIntersection(Circle c1, Circle c2, set<Point>& nodeSet);
};

int countAllinsect(vector<Line> lvec, vector<Circle> cvec, set<Point> &set);
#endif // !CALCULATOR_H_

