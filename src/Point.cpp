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
    //return x==p.x?y<p.y:x<p.x;
    return dcmp(x - p.x) == 0 ? dcmp(y - p.y) < 0 : dcmp(x - p.x) < 0;

}

bool Point::operator ==(const Point& p)const {
    if (dcmp(x-p.x)==0&&dcmp(y-p.y)==0)
        return true;
    return false;
}
 

