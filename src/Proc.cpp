﻿#include <iostream>
#include <set>
#include <map>
#include "Project1.h"

using namespace std;

Proc::Proc() {}

int main() {
	int n;
	int x1;
	int x2;
	int y1;
	int y2;
	char l;
	cin >> n;
	Proc p;
	for (int i = 0; i < n; i++) {
		cin >> l >> x1 >> y1 >> x2 >> y2;
		Line line(x1, y1, x2, y2, i);
		p.preProc(line);
	}
	int result = p.calcPoint();
	cout << result << endl;
}

void Proc::preProc(Line line) {
	map<double, set<Line>>::iterator iter;
	iter = preMap.find(line.getK());
	if (iter != preMap.end()) {
		set<Line> s = iter->second;
		s.insert(line);
		preMap[line.getK()] = s;
	}
	else {
		set<Line> s;
		s.insert(line);
		preMap[line.getK()] = s;
	}
}

int Proc::calcPoint() {
	lineAndLine();
	return pointSet.size();
}

void Proc::lineAndLine() {
	map<double, set<Line>>::iterator iterM;
	for (iterM = preMap.begin(); iterM != preMap.end(); iterM++) {
		set<Line>::iterator iterS;
		set<Line> tempSet = iterM->second;
		//for (iterS = tempSet.begin(); iterS != iterM->second.end(); iterS++)
		for (iterS = tempSet.begin(); iterS != tempSet.end(); iterS++) {
			set<Line>::iterator iterL;
			Line l1 = *iterS;
			set<int> inteId;
			for (iterL = lineSet.begin(); iterL != lineSet.end(); iterL++) {
				Line l2 = *iterL;
				//if find, it is useless to calculate the intersection
				set<int>::iterator iterI = inteId.find(l2.getId());
				if (iterI != inteId.end()) {
					continue;
				}
				Point p = l1.withLine(l2);
				set<Point>::iterator iterP = pointSet.find(p);
				//找到就把点上的线全加进去
				if (iterP != pointSet.end()) {
					p = *iterP;
					set<int>::iterator iterpl;
					set<int> temp = p.getLines();
					for (iterpl = temp.begin(); iterpl != temp.end(); iterpl++) {
						inteId.insert(*iterpl);
					}
					p.addLine(l1.getId());
				}
				else {
					p.addLine(l1.getId());
					p.addLine(l2.getId());
					pointSet.insert(p);
				}
			}
		}
		for (iterS = tempSet.begin(); iterS != tempSet.end(); iterS++) {
			lineSet.insert(*iterS);
		}
	}
}

bool dEqual(double x, double y) {
	double temp;
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