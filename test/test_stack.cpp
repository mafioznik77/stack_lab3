#include "../tStack.h"
#include "gtest.h"

TEST(TStack, can_push_element)
{
TStack<int> TS(3);

ASSERT_NO_THROW(TS.Push(45));
//system ("pause");
}

TEST(TStack, can_create_stack_with_positive_size)
{
ASSERT_NO_THROW(TStack<int> TS(6));
}

TEST(TStack, can_create_stack_with_negative_size)
{
ASSERT_ANY_THROW(TStack<int> TS(-6));  
}

TEST(TStack, can_create_copy_stack)
{
TStack<int> TS1(5);
system ("pause");
ASSERT_NO_THROW(TStack<int> TS2(TS1));
}








