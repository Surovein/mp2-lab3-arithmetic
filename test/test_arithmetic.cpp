// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "arithmetic.h"

TEST(arithm, test1) {
	string x = "1+1";
	vector<Lexema> v = { {"1", OPERAND}, {"+", OPERATION}, {"1", OPERAND} };
}