#include "Calculator.h"

using namespace std;

int main(int argc, char *argv[])
{   
    ifstream infile;
    ofstream outfile;
    //cout << argv[1] << endl;
    //cout << argv[2] << endl;
    //cout << argv[3] << endl;
    //cout << argv[4] << endl;
    
    if (strcmp(argv[1] ,"-i")==0) {
        infile.open(argv[2]);
        if (strcmp(argv[3] , "-o")==0) {
            outfile.open(argv[4]);
        }
    }
    else if (strcmp(argv[3] , "-i")==0) {
        infile.open(argv[4]);
        if (strcmp(argv[1], "-o")==0) {
            outfile.open(argv[2]);
        }
    }


    if (!infile.is_open()) {
        cout << "Can't open the input file!"<<endl;
    }

    if (!outfile.is_open()) {
        cout << "Can't open the output file!" << endl;
    }

      
    Calculator* calc = new Calculator();
    vector<Line> lVec;//存直线
    vector<Circle> cVec;//存圆
    set<Point> nodeSet;
    double n;
    char type;
    double x1, y1, x2, y2, r;
    size_t i, j;
   

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
            calc->haveIntersection(lVec[i], lVec[j], nodeSet);
            //cout << "set:" << nodeSet.size() << endl;
        }
    }

    //计算直线与圆之间的交点
    for (i = 0; i < cVec.size(); i++) {
        for (j = 0; j < lVec.size(); j++) {
            calc->haveIntersection(cVec[i], lVec[j], nodeSet);
            //cout << "set:" << nodeSet.size() << endl;
        }
    }

    //计算两圆之间的交点
    for (i = 0; i < cVec.size(); i++) {
        for (j = i + 1; j < cVec.size(); j++) {
            calc->haveIntersection(cVec[i], cVec[j], nodeSet);
            //cout << "set:" << nodeSet.size() << endl;
        }
    }

    outfile << nodeSet.size();
    cout << "node in Set" << endl;
    for (Point node:nodeSet) {
        cout << "<" << node.x<< "," << node.y << ">" << endl;
    }
    infile.close();
    outfile.close();
}

