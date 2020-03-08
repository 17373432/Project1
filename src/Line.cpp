#include "Project1.h"


Line::Line(int x1, int y1, int x2, int y2, int no) {
	a = (double)y2 - (double)y1;
	b = (double)x1 - (double)x2;
	c = (double)x2 * (double)y1 - (double)x1 * (double)y2;
	id = no;
	if (dEqual(b, 0)) {
		k = inf;
	}
	else {
		k = -a / b;
	}
}


bool Line::operator <(const Line right)const {
	return id < right.id;
}

double Line::getA() {
	return a;
}

double Line::getB() {
	return b;
}

double Line::getC() {
	return c;
}
double Line::getK() {
	return k;
}

int Line::getId() {
	return id;
}

Point Line::withLine(Line l) {
	double a2 = l.getA();
	double b2 = l.getB();
	double c2 = l.getC();
	//a2*b!=a*b2
	double deno = (a2 * b - a * b2);
	double y = (a * c2 - a2 * c) / deno;
	double x = (b2 * c - b * c2) / deno;
	Point p(x, y);
	return p;
}
