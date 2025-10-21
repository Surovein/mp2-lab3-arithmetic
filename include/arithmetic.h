// объ€вление функций и классов дл€ вычислени€ арифметических выражений
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
	vector<Lexema> lexems;;// str[0] == char сравнение строки с символом
	vector<Lexema> lexems_correct;
	map<string, int> priority =
	{
		{ "+",1}, {"-", 1}, {"*",2}, {"/", 2},{"(", 0}
	};
	map<string, int> type =
	{
		{ "+",1}, {"-", 2}, {"*",3}, {"/", 4}
	};
	map<char, double> operands;// дл€ переменных// шаблон
	TArithmeticExpression(string stroka)
	{
		infix = stroka;
	}
	bool Parse()
	{// 1) поиск скобок, удаление их 2)  разбиение на подстроки, получение лексем 3) проверка
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
			tmp.index = infix.find_first_of("()") + count_delete +1; //+1 дл€ того чтобы у 0 индекса индекс был не -1, те у всех операций будет+1 к индексу
			lexems.push_back(tmp);
			infix.erase(infix.find_first_of("()"), 1);
			count_delete += 1;
		}
		if (open != close)
		{
			return false; // ошибка
		}
		while (infix.find_first_of("+*/-") != -1)// знак
		{
			int index = infix.find_first_of("+*/-");
			Lexema tmp;
			tmp.stroka = infix[infix.find_first_of("+*/-")];
			auto it = type.find(tmp.stroka);
			if (it != type.end())// объ€снение
			{
				tmp.type = it->second;;
			}
			tmp.index = index + count_delete +1;
			string substr_left = infix.substr(0, index);// элемент слева от знака
			Lexema tmp2;
			tmp2.stroka = substr_left;
			auto it = type.find(tmp2.stroka);
			if (it != type.end())
			{
				tmp2.type = it->second; // если зайдет сюда, значит два знака подр€д => ошибка
				return false;
			}
			else
			{
				tmp2.type = 0; // 0 - double
			}
			//tmp2.index = tmp.index - 2;
			lexems.push_back(tmp);
			lexems.push_back(tmp2);
			infix.erase(0,infix.find_first_of("+*/-")+1); // наверное так
			count_delete += (infix.find_first_of("+*/-") + 1);
		}
		Lexema tmp;
		tmp.stroka = infix;
		auto it = type.find(tmp.stroka);
		if (it != type.end())// объ€снение
		{
			tmp.type = it->second;// если зайдет сюда, значит два знака подр€д => ошибка
			return false;
		}
		else
		{
			tmp.type = 0;
		}
		//tmp.index = last_index;
		lexems.push_back(tmp);  /// с помощью index сортирую получившийс€ вектор lexem и получаю правильный пор€док лексем
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
				{											// ћен€ем элементы местами
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
		index++; // получаем индекс первого знака
		//lexems_correct.push_back(lexems[index]);// по идее нужно сделать 2 случа€ 1) скобка в начале 2) знак в начале
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