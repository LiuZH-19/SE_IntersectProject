#ifndef POINT_H_
#define POINT_H_

class Point
{
public:
    double x;
    double y;
    Point();
    Point(double a, double b);
    bool operator < (const Point& p)const;
};

#endif // !POINT_H_

