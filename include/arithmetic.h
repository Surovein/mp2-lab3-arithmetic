// объявление функций и классов для вычисления арифметических выражений
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"stack.h"
using namespace std;
class  TArithmeticExpression
{
	string infix;
	string postfix;
	Stack<string> lexems;// str[0] == char сравнение строки с символом
	map<char, int> priority = 
	{
		{'+',1}, {'-', 1}, {'*',2}, {'/', 2},{'(', 0}
	};
	map<char, double> operands;
	TArithmeticExpression(string stroka)
	{
		infix = stroka;
	}
	void Parse()// разбиение на лексемы
	{
		for (int i = 0; i < sizeof(infix); i++)   // 1) создать что то где будут разрешенные символы, сравнивать с ними. 2) если перед нами операнд то его в стек. 3) если числа то идет накопление в новую строку до точки, после нее и до знака операции, полученная строка как то должна сохраниться чтобы пойти в выходную строку.
		{

		}
	}
	void ToPostfix(); // построение постфиксной записи
	string GetInfix() const 
	{
		return infix;
	}
	string GetPostfix() const 
	{
		return postfix;
	}
	vector<char> GetOperands() const;
	double Calculate(const map<char, double>& values);
};