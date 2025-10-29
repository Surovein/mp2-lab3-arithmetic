// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "arithmetic.h"

TEST(arithm, test1) {
	map<char, double> values;
	string stroka = "1,0+1,0";
	vector<Lexema> v = { {"1,0", OPERAND},  {"1,0", OPERAND}, { "+", OPERATION } };
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	vector<Lexema> res = X.GetPostfix();
	EXPECT_EQ(v.size(), res.size());
	for (int i = 0; i < v.size(); i++)
	{
		EXPECT_EQ(v[i].stroka, res[i].stroka);
		EXPECT_EQ(v[i].typeLex, res[i].typeLex);
	}
}
TEST(CAN_CALCULATE,test2)
{
	map<char, double> values;
	string stroka = "(1,0+1,0)*2,0";
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	EXPECT_EQ(4, X.Calculate());
}
TEST(CAN_CALCULATE,test3)
{
	map<char,double> values =
	{
		{ 'a', 1}
	};
	string stroka = "(1,0+a)*2,0";
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	EXPECT_EQ(4, X.Calculate());
}
TEST(CANT_CALCULATE, test4)
{
	map<char, double> values;
	string stroka = "((3,0-1.0)/2,0";
	TArithmeticExpression X(stroka);
	X.Parse2();
	EXPECT_EQ(false, X.check());
}
TEST(CANT_CALCULATE, test5)
{
	map<char, double> values;
	string stroka = "(3,0--1.0)/2,0";
	TArithmeticExpression X(stroka);
	X.Parse2();
	EXPECT_EQ(false, X.check());
}
TEST(arithm2, test6) {
	map<char, double> values;
	string stroka = "1,0+1,0";
	vector<Lexema> v = { {"1,0", OPERAND},{ "+", OPERATION },{"1,0", OPERAND} };
	TArithmeticExpression X(stroka);
	X.Parse2();
	vector<Lexema> res = X.GetLexems();
	EXPECT_EQ(v.size(), res.size());
	for (int i = 0; i < v.size(); i++)
	{
		EXPECT_EQ(v[i].stroka, res[i].stroka);
		EXPECT_EQ(v[i].typeLex, res[i].typeLex);
	}
}
TEST(CAN_CALCULATE, test7)
{
	map<char, double> values;
	string stroka = "(100.125+100.5)*2,0";
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	EXPECT_EQ(401.25, X.Calculate());
}
TEST(CAN_CALCULATE, test8)
{
	map<char, double> values =
	{
		{'a',10}, {'b',20}, {'c',30}
	};
	string stroka = "(a+b)*c";
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	EXPECT_EQ(900, X.Calculate());
}
TEST(CAN_CALCULATE, test9)
{
	map<char, double> values =
	{
		{'a',10}
	};
	string stroka = "(a+a)/a";
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	EXPECT_EQ(2, X.Calculate());
}
TEST(CAN_CALCULATE, test10)
{
	map<char, double> values;
	string stroka = "10000+10000.1";
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	EXPECT_EQ(20000.1, X.Calculate());
}
TEST(CANT_CALCULATE, test11)
{
	map<char, double> values;
	string stroka = "(3,0+-1.0)/2,0";
	TArithmeticExpression X(stroka);
	X.Parse2();
	EXPECT_EQ(false, X.check());
}
TEST(CANT_CALCULATE, test12)
{
	map<char, double> values =
	{
		{'a',10}
	};
	string stroka = "(a+-a)/2,0";
	TArithmeticExpression X(stroka);
	X.Parse2();
	EXPECT_EQ(false, X.check());
}
TEST(CANT_CALCULATE, test13)
{
	map<char, double> values =
	{
		{'a',10}
	};
	string stroka = "aaa";
	TArithmeticExpression X(stroka);
	X.Parse2();
	EXPECT_EQ(false, X.check());
}
TEST(CAN_CALCULATE, test14)
{
	map<char, double> values;
	string stroka = "1.0";
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	EXPECT_EQ(1.0, X.Calculate());
}
TEST(CAN_CALCULATE, test15)
{
	map<char, double> values =
	{
		{'a',10}
	};
	string stroka = "a";
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	EXPECT_EQ(10, X.Calculate());
}
TEST(CAN_CALCULATE, test16)
{
	map<char, double> values =
	{
		{'a',10},{'b',2}, {'c',3}
	};
	string stroka = "(1.0+2.0)*3.0+a+b+c*a";
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	EXPECT_EQ(51, X.Calculate());
}
TEST(CAN_CALCULATE, test17)
{
	map<char, double> values;
	string stroka = "10+(-1)";
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	EXPECT_EQ(9, X.Calculate());
}
TEST(CAN_CALCULATE, test18)
{
	map<char, double> values;
	string stroka = "10*(-1)";
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	EXPECT_EQ(-10, X.Calculate());
}
TEST(arithm3, test19) {
	map<char, double> values;
	string stroka = "1,0+(-1,0)";
	vector<Lexema> v = { {"1,0", OPERAND},  {"-1,0", OPERAND}, { "+", OPERATION } };
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix();
	X.Variable(values);
	vector<Lexema> res = X.GetPostfix();
	EXPECT_EQ(v.size(), res.size());
	for (int i = 0; i < v.size(); i++)
	{
		EXPECT_EQ(v[i].stroka, res[i].stroka);
		EXPECT_EQ(v[i].typeLex, res[i].typeLex);
	}
}