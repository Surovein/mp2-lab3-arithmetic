// реализация пользовательского приложения
#include"arithmetic.h"
#include <locale.h>

int main()
{
	map<char, double> values;
	std::setlocale(LC_NUMERIC, "C");
	setlocale(LC_ALL, "rus");
	string stroka;
	cout << "Введите строку" << endl;
	cin >> stroka;
	TArithmeticExpression X(stroka);
	X.Parse2();
	if (X.check())
	{
		X.ToPostfix(values);
		cout << "Результат" << endl;
		cout << X.Calculate()<<endl;
	}
	else
	{
		//cout << "1344333" << endl;
		cout << "Ошибка ввода"<<endl;
	}
}
