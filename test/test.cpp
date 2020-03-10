﻿#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Project1.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Proc p;
			Line l1(0, 1, 0, 2, 0);
			Line l2(-1, 1, -1, 2, 1);
			p.preProcLine(l1);
			p.preProcLine(l2);
			Assert::AreEqual(0, p.calcPoint());
		}
		TEST_METHOD(TestMethod2)
		{
			Proc p;
			Line l1(99999, 99999, -99999, -99999, 0);
			Line l2(99999, 99999, -99999, -99998, 1);
			p.preProcLine(l1);
			p.preProcLine(l2);
			Assert::AreEqual(1, p.calcPoint());
		}
		TEST_METHOD(TestMethod3)
		{
			Proc p;
			Line l1(99999, 99999, -99999, -99999, 0);
			Line l2(99998, 99998, -99998, -99998, 1);
			p.preProcLine(l1);
			p.preProcLine(l2);
			Assert::AreEqual(0, p.calcPoint());
		}
		TEST_METHOD(TestMethod4)
		{
			Proc p;
			Circle c1(1, 0, 2, 0);
			Circle c2(2, 2, 1, 1);
			Circle c3(3, -2, 6, 2);
			Line l1(-1, 4, 4, 1, 3);
			p.preProcLine(l1);
			p.addCircle(c1);
			p.addCircle(c2);
			p.addCircle(c3);
			int result = p.calcPoint();

			Assert::AreEqual(6, result);
		}
		TEST_METHOD(TestMethod5)
		{
			Proc p;
			Circle c1(0, 0, 2, 0);
			Line l1(2, 0, 2, 2, 1);
			p.preProcLine(l1);
			p.addCircle(c1);
			int result = p.calcPoint();

			Assert::AreEqual(1, result);
		}
		TEST_METHOD(TestMethod6)
		{
			Proc p;
			Circle c1(0, 0, 2, 0);
			Line l1(0, 0, 2, 2, 1);
			p.preProcLine(l1);
			p.addCircle(c1);
			int result = p.calcPoint();

			Assert::AreEqual(2, result);
		}
		TEST_METHOD(TestMethod7)
		{
			Proc p;
			Circle c1(0, 0, 2, 0);
			Line l1(3, 3, 3, 0, 1);
			p.preProcLine(l1);
			p.addCircle(c1);
			int result = p.calcPoint();

			Assert::AreEqual(0, result);
		}
		TEST_METHOD(TestMethod8)
		{
			Proc p;
			Circle c1(0, 0, 2, 0);
			Circle c2(0, 0, 1, 1);
			p.addCircle(c1);
			p.addCircle(c2);
			int result = p.calcPoint();

			Assert::AreEqual(0, result);
		}
		TEST_METHOD(TestMethod9)
		{
			Proc p;
			Circle c1(0, 0, 2, 0);
			Circle c2(1, 0, 1, 1);
			p.addCircle(c1);
			p.addCircle(c2);
			int result = p.calcPoint();

			Assert::AreEqual(1, result);
		}
		TEST_METHOD(TestMethod10)
		{
			Proc p;
			Circle c1(0, 0, 2, 0);
			Circle c2(3, 0, 1, 1);
			p.addCircle(c1);
			p.addCircle(c2);
			int result = p.calcPoint();

			Assert::AreEqual(1, result);
		}
		TEST_METHOD(TestMethod11)
		{
			Proc p;
			Circle c1(0, 0, 2, 0);
			Circle c2(4, 0, 1, 1);
			p.addCircle(c1);
			p.addCircle(c2);
			int result = p.calcPoint();

			Assert::AreEqual(0, result);
		}
		TEST_METHOD(TestMethod12)
		{
			Proc p;
			Circle c1(0, 0, 2, 0);
			Circle c2(1, 0, 2, 1);
			p.addCircle(c1);
			p.addCircle(c2);
			int result = p.calcPoint();

			Assert::AreEqual(2, result);
		}
		TEST_METHOD(TestMethod13)
		{
			Proc p;
			Circle c1(0, 0, 2, 0);
			Circle c2(3, 0, 2, 1);
			p.addCircle(c1);
			p.addCircle(c2);
			int result = p.calcPoint();

			Assert::AreEqual(2, result);
		}
		TEST_METHOD(TestMethod14)
		{
			Proc p;
			Line l1(1, 0, 2, 0, 0);
			Line l2(-1, 1, -1, 2, 1);
			p.preProcLine(l1);
			p.preProcLine(l2);
			Assert::AreEqual(1, p.calcPoint());
		}
	};
}
