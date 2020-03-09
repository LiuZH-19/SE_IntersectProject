#ifndef LINE_H_
#define LINE_H_
class Line
{
public:
	Line(double x1, double y1, double x2, double y2);//构造函数
	double getA();
	double getB();
	double getC();
	//bool operator < (const Line& line) const;
private://直线表示：Ax+By+C=0
	double A;
	double B;
	double C;

};
#endif // !LINE_H_

