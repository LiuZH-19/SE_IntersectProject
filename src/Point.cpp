#include "Point.h"
#include "global.h"
using namespace std;

Point::Point():x(0),y(0) {}
Point::Point(double a, double b)
{
    x = a;
    y = b;
}

bool Point::operator < (const Point& p)const {
        double dx = abs(x - p.x);
        double dy = abs(y - p.y);
        return (dx<EPS ? p.y - y>EPS:p.x - x > EPS);
}
