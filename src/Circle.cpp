#include "Project1.h"

Circle::Circle(int cx, int cy, int cr, int no) {
	Point p((double)cx, (double)cy);
	o = p;
	r = (double)cr;
	id = no;

	r2 = pow(r, 2);
	xx = 2.0 * cx;
	yy = 2.0 * cy;
	x2Ay2Sr2 = pow(cx, 2) + pow(cy, 2) - r2;
}

bool Circle::operator < (const Circle right)const {
	return id < right.id;
}

set<Point> Circle::withLine(Line l) {
	set<Point> s;
	double x0 = o.getX();
	double y0 = o.getY();

	double delta = r2 - pow(l.getA() * x0 + l.getB() * y0 + l.getC(), 2) / l.geta2Ab2();

	if (delta >= 0) {
		double sqrtDelta = sqrt(delta);
		double leftX = (l.getb2() * x0 - l.getab() * y0 - l.getac()) / l.geta2Ab2();
		double rightX = sqrtDelta * l.getCos();
		double leftY = (l.geta2() * y0 - l.getab() * x0 - l.getbc()) / l.geta2Ab2();
		double rightY = sqrtDelta * l.getSin();
		Point p1(leftX - rightX, leftY + rightY);
		Point p2(leftX + rightX, leftY - rightY);
		s.insert(p1);
		s.insert(p2);
	}

	return s;
}

set<Point> Circle::withCircle(Circle that) {
	set<Point> s;
	double max = r + that.r;
	double min = r - that.r;
	if (min < 0) {
		min = -min;
	}
	double d = sqrt(pow(o.getX() - that.o.getX(), 2) + pow(o.getY() - that.o.getY(), 2));

	if (min <= d && d <= max) {
		double A = that.xx - xx;
		double B = that.yy - yy;
		double C = x2Ay2Sr2 - that.x2Ay2Sr2;
		Line l(A, B, C);
		s = withLine(l);
	}

	return s;
}
