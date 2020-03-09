#pragma once
#include <map>
#include <set>
#include <vector>
#include <fstream>

#define eps 0.00000000001
#define inf 1000000

using namespace std;

inline bool dEqual(double x, double y) {
	double temp = 0;
	bool result = false;
	temp = x - y;
	if (temp < 0) {
		temp = -temp;
	}
	if (temp < eps) {
		result = true;
	}
	return result;
}

class Point {
private:
	double x;
	double y;
	vector<int> locateLines;
public:
	Point(double px, double py);
	Point();
	void addLine(int lineId) {
		locateLines.push_back(lineId);
	}
	inline vector<int> getLines() {
		return locateLines;
	}
	inline bool operator < (const Point right)const {
		bool result = false;
		if (x < right.x) {
			result = true;
		}
		else if (dEqual(x, right.x)) {
			if (y < right.y) {
				result = true;
			}
		}
		return result;
	}
	inline bool operator == (const Point right)const {
		bool result = false;
		if (dEqual(x, right.x) && dEqual(y, right.y)) {
			result = true;
		}
		return result;
	}
	inline double getX() {
		return x;
	}
	inline double getY() {
		return y;
	}
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

	void pro() noexcept;
public:
	Line(int x1, int y1, int x2, int y2, int no);
	Line(double A, double B, double C);
	Line();
	bool operator < (const Line right)const {
		return id < right.id;
	}
	inline double getK() {
		return k;
	}
	inline double getA() {
		return a;
	}
	inline double getB() {
		return b;
	}
	inline double getC() {
		return c;
	}
	inline int getId() {
		return id;
	}

	Point withLine(Line l);

	inline double geta2Ab2() {
		return a2Ab2;
	}
	inline double getb2() {
		return b2;
	}
	inline double getab() {
		return ab;
	}
	inline double getac() {
		return ac;
	}
	inline double geta2() {
		return a2;
	}
	inline double getbc() {
		return bc;
	}
	inline double getCos() {
		return cos;
	}
	inline double getSin() {
		return sin;
	}
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
	Circle();
	vector<Point> withLine(Line l);
	vector<Point> withCircle(Circle that);
	inline bool operator < (const Circle right)const {
		return id < right.id;
	}
};

class Proc {
private:
	map<double, vector<Line>> preMap;
	set<Point> pointSet;
	int num;
	vector<Line> lineSet;
	vector<Circle> circleSet;
public:
	Proc();
	int process(ifstream& in);
	void preProcLine(Line line);
	int calcPoint();
	void lineAndLine();
	void addCircle(Circle circle) {
		circleSet.push_back(circle);
	}
	void calcCircle();
	void lineAndCircle(Circle circle);
};
