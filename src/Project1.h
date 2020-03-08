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
	Point();
	void addLine(int lineId);
	set<int> getLines();
	bool operator < (const Point right)const;
	double getX();
	double getY();
};

class Line {
private:
	double a;
	double b;
	double c;
	double k;
	int id;

	double a2Ab2;
	double b2;
	double ab;
	double ac;
	double a2;
	double bc;
	double cos;
	double sin;

	void pro();
public:
	Line(int x1, int y1, int x2, int y2, int no);
	Line(double A, double B, double C);
	bool operator < (const Line right)const;
	double getK();
	double getA();
	double getB();
	double getC();
	int getId();
	Point withLine(Line l);

	double geta2Ab2();
	double getb2();
	double getab();
	double getac();
	double geta2();
	double getbc();
	double getCos();
	double getSin();
};

class Circle {
private:
	Point o;
	double r;
	int id;

	double r2;
	double xx;
	double yy;
	double x2Ay2Sr2;
public:
	Circle(int cx, int cy, int cr, int no);
	set<Point> withLine(Line l);
	set<Point> withCircle(Circle that);
	bool operator < (const Circle right)const;
};

class Proc {
private:
	map<double, set<Line>> preMap;
	set<Point> pointSet;
	set<Line> lineSet;
	set<Circle> circleSet;
public:
	Proc();
	void preProcLine(Line line);
	int calcPoint();
	void lineAndLine();
	void addCircle(Circle circle);
	void calcCircle();
	void lineAndCircle(Circle circle);
};



bool dEqual(double x, double y);
