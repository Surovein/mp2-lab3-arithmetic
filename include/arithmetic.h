// ���������� ������� � ������� ��� ���������� �������������� ���������
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"stack.h"
using namespace std;


enum LEXEM_TYPE {
	OPERAND,
	OPERATION,
	BRACKET,
	VARIABLE
};

struct Lexema
{
	string stroka;
	int index = -1;
	LEXEM_TYPE typeLex;
};
class  TArithmeticExpression
{
	string infix;
	string postfix;
	vector<Lexema> postfix;
	vector<Lexema> lexems;;// str[0] == char ��������� ������ � ��������
	map<string, int> priority =
	{
		{ "+",1}, {"-", 1}, {"*",2}, {"/", 2},{"(", 0}
	};
	map<char, double> operands;// ��� ����������// ������





public:

	TArithmeticExpression(string stroka)
	{
		infix = stroka;
	}

	vector<Lexema> getLexems()	
	{
		return lexems;
	}

	//bool Parse()
	//{// 1) ����� ������, �������� �� 2)  ��������� �� ���������, ��������� ������ 3) ��������
	//	int last_index = sizeof(infix) - 1;
	//	int open = 0;
	//	int close = 0;
	//	int count_delete = 0;
	//	int pos = 0;
	//	while (infix.find_first_of("()") != -1) 
	//	{
	//		Lexema tmp;
	//		tmp.stroka = infix[infix.find_first_of("()")];
	//		if (tmp.stroka == "(")
	//		{
	//			open++;
	//		}
	//		else
	//		{
	//			close++;
	//		}
	//		tmp.type = 5;
	//		tmp.index = infix.find_first_of("()") + count_delete +1; //+1 ��� ���� ����� � 0 ������� ������ ��� �� -1, �� � ���� �������� �����+1 � �������
	//		lexems.push_back(tmp);
	//		infix.erase(infix.find_first_of("()"), 1);
	//		count_delete += 1;
	//	}
	//	if (open != close)
	//	{
	//		return false; // ������
	//	}
	//	while (infix.find_first_of("+*/-") != -1)// ����
	//	{
	//		int index = infix.find_first_of("+*/-");
	//		Lexema tmp;
	//		tmp.stroka = infix[infix.find_first_of("+*/-")];
	//		auto it = type.find(tmp.stroka);
	//		if (it != type.end())// ����������
	//		{
	//			tmp.type = it->second;;
	//		}
	//		tmp.index = index + count_delete +1;
	//		string substr_left = infix.substr(0, index);// ������� ����� �� �����
	//		Lexema tmp2;
	//		tmp2.stroka = substr_left;
	//		auto it = type.find(tmp2.stroka);
	//		if (it != type.end())
	//		{
	//			tmp2.type = it->second; // ���� ������ ����, ������ ��� ����� ������ => ������
	//			return false;
	//		}
	//		else
	//		{
	//			tmp2.type = 0; // 0 - double
	//		}
	//		tmp2.index = tmp.index - 2;
	//		lexems.push_back(tmp);
	//		lexems.push_back(tmp2);
	//		infix.erase(0,infix.find_first_of("+*/-")+1); // �������� ���
	//		count_delete += (infix.find_first_of("+*/-") + 1);
	//	}
	//	Lexema tmp;
	//	tmp.stroka = infix;
	//	auto it = type.find(tmp.stroka);
	//	if (it != type.end())// ����������
	//	{
	//		tmp.type = it->second;// ���� ������ ����, ������ ��� ����� ������ => ������
	//		return false;
	//	}
	//	else
	//	{
	//		tmp.type = 0;
	//	}
	//	tmp.index = last_index;
	//	lexems.push_back(tmp);  /// � ������� index �������� ������������ ������ lexem � ������� ���������� ������� ������
	//	return true;
	//}


	void Parse2()
	{
		int open = 0;
		int close = 0;
		int pos = 0;


		while (pos < infix.size()) {
			string x = string(infix[pos], 1);
			if (x.find_first_of("()") != -1)
			{
				Lexema tmp;
				tmp.stroka = x;
				if (tmp.stroka == "(")
				{
					open++;
				}
				else
				{
					close++;
				}
				tmp.typeLex = BRACKET;
				lexems.push_back(tmp);
				pos++;
			}

			else if (x.find_first_of("+*/-") != -1)// ����
			{
				Lexema tmp;
				tmp.stroka = x;
				tmp.typeLex = OPERATION;
				lexems.push_back(tmp);
				pos++;
			}
			else {

				// aa + bb
				if (isalpha(infix[pos])) {
					// ����� �����
					Lexema tmp;
					tmp.stroka = x;
					tmp.typeLex = VARIABLE;
					lexems.push_back(tmp);
					pos++;
				}
				else if (isdigit(infix[pos])) {
					pos++;
					while (isdigit(infix[pos]) || (infix[pos] == '.'))
					{
						x += string(infix[pos], 1);
						pos++;
					}
					// x = "123.45"
					Lexema tmp;
					tmp.stroka = x;
					tmp.typeLex = OPERAND;
					lexems.push_back(tmp);// ��� �� ��� ����� ��������� � double
				}
			}
		}
	}
	bool check()
	{
		int open = 0;
		int close = 0;
		for (int i = 0; i < sizeof(lexems) - 1; i++)
		{
			if (lexems[i].typeLex == lexems[i + 1].typeLex && lexems[i].typeLex != BRACKET && lexems[i+1].typeLex!= BRACKET)
			{
				return false;
			}
			if (lexems[i].stroka == "(")
			{
				open++;
			}
			else
			{
				close++;
			}
			
		}
		if (lexems[sizeof(lexems) - 1].stroka == "(")
		{
			open++;
		}
		else
		{
			close++;
		}
		if (close != open)
		{
			return false;
		}
		return true;
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