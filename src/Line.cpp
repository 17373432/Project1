#include "Project1.h"


Line::Line(int x1, int y1, int x2, int y2, int no) {
	a = (double)y2 - (double)y1;
	b = (double)x1 - (double)x2;
	c = (double)x2 * (double)y1 - (double)x1 * (double)y2;
	id = no;
	pro();
}

Line::Line(double A, double B, double C) {
	a = A;
	b = B;
	c = C;
	id = -1;
	pro();
}

void Line::pro() {
	if (dEqual(b, 0)) {
		k = inf;
	}
	else {
		k = -a / b;
	}

	a2 = pow(a, 2);
	b2 = pow(b, 2);
	a2Ab2 = a2 + b2;
	ab = a * b;
	ac = a * c;
	bc = b * c;
	cos = b / sqrt(a2Ab2);
	sin = a / sqrt(a2Ab2);
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

double Line::geta2Ab2() {
	return a2Ab2;
}

double Line::getb2() {
	return b2;
}

double Line::getab() {
	return ab;
}

double Line::getac() {
	return ac;
}

double Line::geta2() {
	return a2;
}

double Line::getbc() {
	return bc;
}

double Line::getCos() {
	return cos;
}

double Line::getSin() {
	return sin;
}
