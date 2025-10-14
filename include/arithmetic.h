// ���������� ������� � ������� ��� ���������� �������������� ���������
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
	Stack<string> lexems;// str[0] == char ��������� ������ � ��������
	map<char, int> priority = 
	{
		{'+',1}, {'-', 1}, {'*',2}, {'/', 2},{'(', 0}
	};
	map<char, double> operands;
	TArithmeticExpression(string stroka)
	{
		infix = stroka;
	}
	void Parse()// ��������� �� �������
	{
		for (int i = 0; i < sizeof(infix); i++)   // 1) ������� ��� �� ��� ����� ����������� �������, ���������� � ����. 2) ���� ����� ���� ������� �� ��� � ����. 3) ���� ����� �� ���� ���������� � ����� ������ �� �����, ����� ��� � �� ����� ��������, ���������� ������ ��� �� ������ ����������� ����� ����� � �������� ������.
		{

		}
	}
	void ToPostfix(); // ���������� ����������� ������
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