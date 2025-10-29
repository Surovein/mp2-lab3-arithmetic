// тесты для стека

#include "stack.h"
#include <gtest.h>
TEST(PUSH_POP, test1)
{
	Stack<int> stack(5);
	stack.push(3);
	EXPECT_EQ(3, stack.pop());
}
TEST(SIZE, test2)
{
	Stack<int> stack(5);
	stack.push(3);
	stack.push(2);
	stack.push(1);
	EXPECT_EQ(3, stack.stack_real_size());
}
TEST(TOP_INDEX, test3)
{
	Stack<int> stack(5);
	stack.push(3);
	EXPECT_EQ(3, stack.top());
}