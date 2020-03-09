#include "Project1.h"


Line::Line(int x1, int y1, int x2, int y2, int no) {
	a = static_cast<double>(y2) - static_cast<double>(y1);
	b = static_cast<double>(x1) - static_cast<double>(x2);
	c = static_cast<double>(x2)* static_cast<double>(y1) - static_cast<double>(x1)* static_cast<double>(y2);
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

void Line::pro() noexcept {
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


Point Line::withLine(Line l) {
	const double a2 = l.getA();
	double b2 = l.getB();
	double c2 = l.getC();
	//a2*b!=a*b2
	double deno = (a2 * b - a * b2);
	double y = (a * c2 - a2 * c) / deno;
	double x = (b2 * c - b * c2) / deno;
	Point p(x, y);
	return p;
}

Line::Line() {
	a = b = c = id = 0;
	pro();
}
