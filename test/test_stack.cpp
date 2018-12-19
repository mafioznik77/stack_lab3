#include "../tStack.h"
#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size)
{
	ASSERT_NO_THROW(TStack<int> TS(6));
}

TEST(TStack, throws_when_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack<int> TS(-6));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> TS1(5);

	ASSERT_NO_THROW(TStack<int> TS2(TS1));
}

TEST(TStack, created_stack_is_empty)
{
	TStack<int> TS(5);

	ASSERT_TRUE(TS.IsEmpty());
}

TEST(TStack, can_push_element)
{
	TStack<int> TS(3);
	for (int i = 0; i<3; i++)
		TS.Push(i);
	ASSERT_ANY_THROW(TS.Push(2));
}

TEST(TStack, can_pop_element) 
{
	TStack<int> TS(5);

	for (int i = 0; i<5; i++)
		TS.Push(i);
	ASSERT_NO_THROW(TS.Pop());

}

TEST(TStack, can_check_top_element)
{
	TStack<int> TS(3);

	TS.Push(5);

	EXPECT_EQ(5, TS.Top());
}

TEST(TStack, throws_when_pop_empty_stack)
{
	TStack<int> St(0);
	ASSERT_ANY_THROW(St.Pop());
}

TEST(TStack, throws_when_stack_full)
{
	TStack<int> TS(1);
	TS.Push(1);
	ASSERT_ANY_THROW(TS.Push(1));
}

TEST(TStack, can_clear_stack)
{
	TStack<int> TS(5);

	TS.Push(1);

	TS.Clr();

	ASSERT_TRUE(TS.IsEmpty());
	system("pause");
}