#ifndef CIRCLE_H_
#define CIRCLE_H_
class Circle
{
public:
	Circle(double x, double y, double r);//���캯��
	double getX();
	double getY();
	double getR();
private://ֱ�߱�ʾ��Ax+By+C=0
	double X;
	double Y;
	double R;
};
#endif // !CIRCLE_H_

