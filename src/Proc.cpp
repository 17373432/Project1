#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include "Project1.h"

using namespace std;

Proc::Proc() {
	num = 0;
}

int main(int argc, char* argv[]) {
	int n;
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	int r1 = 0;
	char c = '\0';
	ifstream in(argv[2]);
	ofstream out(argv[4]);
	in >> n;
	Proc p;
	for (int i = 0; i < n; i++) {
		in >> c;
		if (c == 'L') {
			in >> x1 >> y1 >> x2 >> y2;
			Line line(x1, y1, x2, y2, i);
			p.preProcLine(line);
		}
		else if (c == 'C') {
			in >> x1 >> y1 >> r1;
			Circle circle(x1, y1, r1, i);
			p.addCircle(circle);
		}
	}
	int result = p.calcPoint();
	out << result << endl;
	in.close();
	out.close();
}

void Proc::preProcLine(Line line) {
	map<double, vector<Line>>::iterator iter;
	iter = preMap.find(line.getK());
	if (iter != preMap.end()) {
		vector<Line> s = iter->second;
		s.push_back(line);
		preMap[line.getK()] = s;
	}
	else {
		vector<Line> s;
		s.push_back(line);
		preMap[line.getK()] = s;
	}
}


int Proc::calcPoint() {
	lineAndLine();
	calcCircle();
	return pointSet.size();
}

void Proc::lineAndLine() {
	map<double, vector<Line>>::iterator iterM;
	for (iterM = preMap.begin(); iterM != preMap.end(); iterM++) {
		vector<Line>::iterator iterS;
		vector<Line> tempSet = iterM->second;
		//for (iterS = tempSet.begin(); iterS != iterM->second.end(); iterS++)
		for (iterS = tempSet.begin(); iterS != tempSet.end(); iterS++) {
			vector<Line>::iterator iterL;
			Line l1 = *iterS;
			//set or vector?
			vector<int> inteId;
			for (iterL = lineSet.begin(); iterL != lineSet.end(); iterL++) {
				Line l2 = *iterL;
				//if find, it is useless to calculate the intersection
				if (find(inteId.begin(), inteId.end(), l2.getId()) != inteId.end()) {
					continue;
				}
				Point p = l1.withLine(l2);
				set<Point>::iterator iterP = pointSet.find(p);
				//找到就把点上的线全加进去
				if (iterP != pointSet.end()) {
					p = *iterP;
					vector<int>::iterator iterpl;
					vector<int> temp = p.getLines();
					for (iterpl = temp.begin(); iterpl != temp.end(); iterpl++) {
						inteId.push_back(*iterpl);
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
			lineSet.push_back(*iterS);
		}
	}
}

void Proc::calcCircle() {
	vector<Circle>::iterator iter1;
	for (iter1 = circleSet.begin(); iter1 != circleSet.end(); iter1++) {
		vector<Circle>::iterator iter2;
		Circle circle1 = *iter1;
		lineAndCircle(circle1);
		for (iter2 = circleSet.begin(); iter2 != iter1; iter2++) {
			Circle circle2 = *iter2;
			vector<Point> s = circle1.withCircle(circle2);
			vector<Point>::iterator iterS;
			for (iterS = s.begin(); iterS != s.end(); iterS++) {
				pointSet.insert(*iterS);
			}
		}
	}
}

void Proc::lineAndCircle(Circle circle) {
	vector<Point> result;
	map<double, vector<Line>>::iterator iterM;
	for (iterM = preMap.begin(); iterM != preMap.end(); iterM++) {
		vector<Line>::iterator iterS;
		vector<Line> tempSet = iterM->second;
		//for (iterS = tempSet.begin(); iterS != iterM->second.end(); iterS++)
		for (iterS = tempSet.begin(); iterS != tempSet.end(); iterS++) {
			Line l = *iterS;
			vector<Point> s = circle.withLine(l);
			vector<Point>::iterator iterS;
			for (iterS = s.begin(); iterS != s.end(); iterS++) {
				pointSet.insert(*iterS);
			}
		}
	}
}
