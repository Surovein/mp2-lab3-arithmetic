// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "arithmetic.h"

TEST(arithm, test1) {
	map<char, double> values;
	string stroka = "1,0+1,0";
	vector<Lexema> v = { {"1,0", OPERAND},  {"1,0", OPERAND}, { "+", OPERATION } };
	TArithmeticExpression X(stroka);
	X.Parse2();
	X.ToPostfix(values);
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
	X.ToPostfix(values);
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
	X.ToPostfix(values);
	EXPECT_EQ(4, X.Calculate());
}