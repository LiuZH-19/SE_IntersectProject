#ifndef CIRCLE_H_
#define CIRCLE_H_
class Circle
{
public:
	Circle(double x, double y, double r);//构造函数
	double getX();
	double getY();
	double getR();
private://直线表示：Ax+By+C=0
	double X;
	double Y;
	double R;
};
#endif // !CIRCLE_H_

