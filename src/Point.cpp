#include "Project1.h"

Point::Point(double px, double py) {
	x = px;
	y = py;
}

Point::Point() {
	x = 0;
	y = 0;
}


void Point::addLine(int lineId) {
	locateLines.insert(lineId);
}

set<int> Point::getLines() {
	return locateLines;
}

bool Point::operator < (const Point right)const {
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

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}
