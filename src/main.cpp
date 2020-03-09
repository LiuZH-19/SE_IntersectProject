#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include "Line.h"
#include "Circle.h"

using namespace std;

//此处传引用
int twoLine(Line l1, Line l2, set<pair<double,double>> &nodeSet) {
    double A1 = l1.getA();
    double B1 = l1.getB();
    double C1 = l1.getC();
    double A2 = l2.getA();
    double B2 = l2.getB();
    double C2 = l2.getC();
    double den = A1 * B2 - A2 * B1;
    if (den == 0)
        return 0;
    double num1 = B1 * C2 - B2 * C1;
    double num2 = A2 * C1 - A1 * C2;
    pair<double, double> node(num1 / den, num2 / den);
    cout << "one node!" << endl;
    nodeSet.insert(node);
    cout << nodeSet.size() << endl;
    return 1;
}

int lineAndCircle(Circle c, Line l,set<pair<double, double>>& nodeSet) {
    double A = l.getA();
    double B = l.getB();
    double C = l.getC();
    double X = c.getX();
    double Y = c.getY();
    double R = c.getR();
    double d = abs(A * X + B * Y + C) / sqrt(A * A + B * B);
    if (d-R > 0.00000001) {
        return 0;
    }
    else {
        double x0 = (B * B * X - A * B * Y - A * C) / (A * A + B * B);
        double y0 = (A * A * Y - A * B * X - B * C) / (A * A + B * B);
        if (abs(d-R)<0.0000001){ //直线与圆相切
            pair<double, double> node(x0, y0);
            nodeSet.insert(node);
            return 1;
        }
        else {//直线与圆相交
            double a = sqrt(R * R - d * d);
            pair<double, double> node1;
            pair<double, double> node2;
            if (B == 0) {
                node1.first = x0;
                node1.second = y0 + a;
                node2.first = x0;
                node2.second = y0 - a;
                nodeSet.insert(node1);
                nodeSet.insert(node2);
            }
            else {
                double k = -A / B;
                double cos = 1 / sqrt(1 + k * k);
                double sin = k / sqrt(1 + k * k);
                node1.first = x0 + a * cos;
                node1.second = y0 + a * sin;
                node2.first = x0 - a * cos;
                node2.second = y0 - a * sin;
                nodeSet.insert(node1);
                nodeSet.insert(node2);
            }
            return 2;

        }

    }



}


int twoCircle(Circle c1, Circle c2, set<pair<double, double>>& nodeSet) {
    int count = 0;
    double a1 = c1.getX();
    double b1 = c1.getY();
    double r1 = c1.getR();
    double a2 = c2.getX();
    double b2 = c2.getY();
    double r2 = c2.getR();

    double subs1 = a1*a1 - 2 * a1 * a2 + a2*a2 + b1*b1 - 2 * b1 * b2 + b2*b2;
    double subs2 = -r1*r1 * a1 + r1*r1 * a2 + r2*r2 * a1 - r2*r2 * a2 + a1*a1 * a1
                - a1*a1 * a2 - a1 * a2*a2 + a1 * b1*b1 - 2 * a1 * b1 * b2 + a1 * b2*b2 
                + a2*a2 * a2 + a2 * b1*b1 - 2 * a2 * b1 * b2 + a2 * b2*b2;
    double subs3 = -r1*r1 * b1 + r1*r1 * b2 + r2*r2 * b1 - r2*r2 * b2 + a1*a1* b1 
                + a1*a1 * b2 - 2 * a1 * a2 * b1 - 2 * a1 * a2 * b2 + a2*a2 * b1 
                + a2*a2 * b2 + b1*b1 * b1 - b1*b1 * b2 - b1 * b2*b2 + b2*b2 * b2;
    double sigma = sqrt((r1*r1 + 2 * r1 * r2 + r2*r2 - a1*a1 + 2 * a1 * a2 - a2*a2 - b1*b1 + 2 * b1 * b2 - b2*b2) 
        * (-r1*r1 + 2 * r1 * r2 - r2*r2 + subs1));

    if (abs(subs1) > 0.0000001)//分母不为0
    {
        double x1 = (subs2 - sigma * b1 + sigma * b2) / (2 * subs1);
        double y1 = (subs3 + sigma * a1 - sigma * a2) / (2 * subs1);
        pair<double, double> node1(x1, y1);
        nodeSet.insert(node1);
        count++;
        if (sigma > 0.0000001) {//两圆不相切
            double x2 = (subs2 + sigma * b1 - sigma * b2) / (2 * subs1);
            double y2 = (subs3 - sigma * a1 + sigma * a2) / (2 * subs1);
            pair<double, double> node2(x2, y2);
            nodeSet.insert(node2);
            count++;
        }

    }
    return count;

}


int main()
{
    ifstream infile;
    infile.open("input.txt");
    if (!infile.is_open()) {
        cout << "Can't open the file!"<<endl;
    }
    ofstream outfile;
    outfile.open("output.txt");   

    vector<Line> lVec;//存直线
    vector<Circle> cVec;//存圆
    set<pair<double, double>> nodeSet;
    double n;
    char type;
    double x1;
    double y1;
    double x2;
    double y2;
    double r;
    int i;
    int j;

    infile >> n;
    for ( i = 0; i < n; i++) {
        infile >> type;
        if (type == 'L') {
            infile >> x1 >> y1 >> x2 >> y2;
            Line line(x1, y1, x2, y2);
            lVec.push_back(line);
        }
        else {
            infile >> x1 >> y1 >> r;
            Circle circle(x1, y1, r);
            cVec.push_back(circle);
        }
    }
    
    //计算两条直线间的交点
    for (i = 0; i < lVec.size(); i++) {
        for (j = i + 1; j < lVec.size(); j++) {
            twoLine(lVec[i], lVec[j], nodeSet);
            //cout << "set:" << nodeSet.size() << endl;
        }
    }

    //计算直线与圆之间的交点
    for (i = 0; i < cVec.size(); i++) {
        for (j = 0; j < lVec.size(); j++) {
            lineAndCircle(cVec[i], lVec[j], nodeSet);
            //cout << "set:" << nodeSet.size() << endl;
        }
    }

    //计算两圆之间的交点
    for (i = 0; i < cVec.size(); i++) {
        for (j = i + 1; j < cVec.size(); j++) {
            twoCircle(cVec[i], cVec[j], nodeSet);
            //cout << "set:" << nodeSet.size() << endl;
        }
    }

    outfile << nodeSet.size();
    infile.close();
    outfile.close();
}

