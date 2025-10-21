// ���������� ������� � ������� ��� ���������� �������������� ���������
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"stack.h"
using namespace std;
struct Lexema
{
	string stroka;
	int type;
	int index = -1;
};
class  TArithmeticExpression
{
	string infix;
	string postfix;
	vector<Lexema> postfix;
	vector<Lexema> lexems;;// str[0] == char ��������� ������ � ��������
	vector<Lexema> lexems_correct;
	map<string, int> priority =
	{
		{ "+",1}, {"-", 1}, {"*",2}, {"/", 2},{"(", 0}
	};
	map<string, int> type =
	{
		{ "+",1}, {"-", 2}, {"*",3}, {"/", 4}
	};
	map<char, double> operands;// ��� ����������// ������
	TArithmeticExpression(string stroka)
	{
		infix = stroka;
	}
	bool Parse()
	{// 1) ����� ������, �������� �� 2)  ��������� �� ���������, ��������� ������ 3) ��������
		int last_index = sizeof(infix) - 1;
		int open = 0;
		int close = 0;
		int count_delete = 0;
		while (infix.find_first_of("()") != -1) 
		{
			Lexema tmp;
			tmp.stroka = infix[infix.find_first_of("()")];
			if (tmp.stroka == "(")
			{
				open++;
			}
			else
			{
				close++;
			}
			tmp.type = 5;
			tmp.index = infix.find_first_of("()") + count_delete +1; //+1 ��� ���� ����� � 0 ������� ������ ��� �� -1, �� � ���� �������� �����+1 � �������
			lexems.push_back(tmp);
			infix.erase(infix.find_first_of("()"), 1);
			count_delete += 1;
		}
		if (open != close)
		{
			return false; // ������
		}
		while (infix.find_first_of("+*/-") != -1)// ����
		{
			int index = infix.find_first_of("+*/-");
			Lexema tmp;
			tmp.stroka = infix[infix.find_first_of("+*/-")];
			auto it = type.find(tmp.stroka);
			if (it != type.end())// ����������
			{
				tmp.type = it->second;;
			}
			tmp.index = index + count_delete +1;
			string substr_left = infix.substr(0, index);// ������� ����� �� �����
			Lexema tmp2;
			tmp2.stroka = substr_left;
			auto it = type.find(tmp2.stroka);
			if (it != type.end())
			{
				tmp2.type = it->second; // ���� ������ ����, ������ ��� ����� ������ => ������
				return false;
			}
			else
			{
				tmp2.type = 0; // 0 - double
			}
			//tmp2.index = tmp.index - 2;
			lexems.push_back(tmp);
			lexems.push_back(tmp2);
			infix.erase(0,infix.find_first_of("+*/-")+1); // �������� ���
			count_delete += (infix.find_first_of("+*/-") + 1);
		}
		Lexema tmp;
		tmp.stroka = infix;
		auto it = type.find(tmp.stroka);
		if (it != type.end())// ����������
		{
			tmp.type = it->second;// ���� ������ ����, ������ ��� ����� ������ => ������
			return false;
		}
		else
		{
			tmp.type = 0;
		}
		//tmp.index = last_index;
		lexems.push_back(tmp);  /// � ������� index �������� ������������ ������ lexem � ������� ���������� ������� ������
		return true;
	}
	void sort()
	{
		int n = lexems.size();

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (lexems[j].index > lexems[j + 1].index)
				{											// ������ �������� �������
					swap(lexems[j], lexems[j + 1]);
				}
			}
		}
	}
	void create_correct_vector()
	{
		int index = 0;
		while (lexems[index].index == -1)
		{
			index++;
		}
		index++; // �������� ������ ������� �����
		//lexems_correct.push_back(lexems[index]);// �� ���� ����� ������� 2 ������ 1) ������ � ������ 2) ���� � ������
		int i = 0;
		for (int index; index < lexems.size(); i++)
		{
			//if (index = lexems.size() - 1)
			//{
			//	lexems_correct.push_back(lexems[index]);
			//	lexems_correct.push_back(lexems[i]);
			//}
			if (lexems[index].index != lexems[index + 1].index + 1)
			{
				lexems_correct.push_back(lexems[i]);
				lexems_correct.push_back(lexems[index + 1]);
				index++;
				i++;
			}
			else
			{
				lexems_correct.push_back(lexems[index + 1]);
				index++;
			}
			//lexems_correct.push_back(lexems[index]);
			if()
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