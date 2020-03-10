#include "Calculator.h"
#include <iostream>
using namespace std;

void outNode(Point node) {
    cout << "<" << node.x << "," << node.y << ">" << endl;
}

Calculator::Calculator() {}
//�˴�������
int Calculator::haveIntersection(Line l1, Line l2, set<Point>& nodeSet) {
    double A1 = l1.A;
    double B1 = l1.B;
    double C1 = l1.C;
    double A2 = l2.A;
    double B2 = l2.B;
    double C2 = l2.C;
    double den = A1 * B2 - A2 * B1;
    if (den==0)
        return 0;
    double num1 = B1 * C2 - B2 * C1;
    double num2 = A2 * C1 - A1 * C2;
    Point  node(num1 / den, num2 / den);
    nodeSet.insert(node);
    outNode(node);//!
    return 1;
}

int Calculator::haveIntersection(Circle c, Line l, set<Point>& nodeSet) {
    double A = l.A;
    double B = l.B;
    double C = l.C;
    double X = c.X;
    double Y = c.Y;
    double R = c.R;
    double  den = A * A + B * B;
    double d = abs(A * X + B * Y + C) / sqrt(den);
    if (d - R > EPS) {
        return 0;
    }
    else {
        double x0 = (B * B * X - A * B * Y - A * C) / (den);
        double y0 = (A * A * Y - A * B * X - B * C) / (den);
        if (abs(d - R) < EPS) { //ֱ����Բ����
            Point node(x0, y0);
            nodeSet.insert(node);
            outNode(node);//!
            return 1;
        }
        else {//ֱ����Բ�ཻ
            double a = sqrt(R * R - d * d);
            if (B == 0) {
                Point node1(x0, y0 + a);
                Point node2(x0, y0 - a);
                nodeSet.insert(node1);
                nodeSet.insert(node2);
                outNode(node1);//!
                outNode(node2);//!
            }
            else {
                double k = -A / B;
                double cos = 1 / sqrt(1 + k * k);
                double sin = k / sqrt(1 + k * k);
                Point node1(x0 + a * cos, y0 + a * sin);
                Point node2(x0 - a * cos, y0 - a * sin);
                nodeSet.insert(node1);
                nodeSet.insert(node2);
                outNode(node1);//!
                outNode(node2);//!
            }
            return 2;

        }

    }



}


int Calculator::haveIntersection(Circle c1, Circle c2, set<Point>& nodeSet) {
    double a1 = c1.X;
    double b1 = c1.Y;
    double r1 = c1.R;
    double a2 = c2.X;
    double b2 = c2.Y;
    double r2 = c2.R;

    //���һЩ��ֵ  �򻯼���
    double r11 = r1 * r1;
    double a11 = a1 * a1;
    double b11 = b1 * b1;
    double r22 = r2 * r2;
    double a22 = a2 * a2;
    double b22 = b2 * b2;

    double r12 = r1 * r2;
    double a12 = a1 * a2;
    double b12 = b1 * b2;

    double subs1 = a11- 2 * a12 + a22 + b11 - 2 * b12 + b22;
    
    double subs2 = -r11 * a1 + r11 * a2 + r22 * a1 - r22* a2 + a11 * a1
        - a11 * a2 - a1 * a22 + a1 * b11 - 2 * a1 * b12 + a1 * b22
        + a22 * a2 + a2 * b11 - 2 * a2 * b12 + a2 * b22;
    double subs3 = -r11 * b1 + r11 * b2 + r22 * b1 - r22 * b2 + a11 * b1
        + a11 * b2 - 2 * a12 * b1 - 2 * a12 * b2 + a22 * b1
        + a22 * b2 + b11 * b1 - b11 * b2 - b1 * b22 + b22 * b2;

    double s = (r11 + 2 * r12 + r22 - subs1)* (-r11 + 2 * r12 - r22 + subs1);
    if (s < 0||subs1==0) {//���� �� �ں� ͬ��
        return 0;
    }
    else if (s == 0) {
        Point node(subs2 / (2 * subs1), subs3 / (2 * subs1));
        nodeSet.insert(node);
        outNode(node);//!
        return 1;
    }
    else { //�ཻ
        double sigma = sqrt(s);        
        double dx = sigma * (b1 - b2);
        double dy = sigma * (a2 - a1);
        double x1 = (subs2 - dx) / (2 * subs1);
        double y1 = (subs3 - dy) / (2 * subs1);
        Point  node1(x1, y1);
        nodeSet.insert(node1);
        double x2 = (subs2 + dx) / (2 * subs1);
        double y2 = (subs3 + dy) / (2 * subs1);
        Point  node2(x2, y2);
        nodeSet.insert(node2);
        outNode(node1);//!
        outNode(node2);//!
        return 2;        
    }
  
}
