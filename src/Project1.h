#pragma once
#include <map>
#include <set>

#define eps 0.00000000001
#define inf 1000000

using namespace std;

class Point {
private:
	double x;
	double y;
	set<int> locateLines;
public:
	Point(double px, double py);
	void addLine(int lineId);
	set<int> getLines();
	bool operator < (const Point right)const;
};

class Line {
private:
	double a;
	double b;
	double c;
	double k;
	int id;
public:
	Line(int x1, int y1, int x2, int y2, int no);
	bool operator < (const Line right)const;
	double getK();
	double getA();
	double getB();
	double getC();
	int getId();
	Point withLine(Line l);
};

class Proc {
private:
	map<double, set<Line>> preMap;
	set<Point> pointSet;
	set<Line> lineSet;
public:
	Proc();
	void preProc(Line line);
	int calcPoint();
	void lineAndLine();
};

bool dEqual(double x, double y);
