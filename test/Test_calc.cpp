#include "../Tcalc.h"
#include "gtest.h"
TEST(TCalculator, check_brackets_1_true)
{
	TCalculator test;
	test.SetInf("()");
	EXPECT_EQ(true, test.CheckBrackets());
}

TEST(TCalculator, check_brackets_2_true)
{
	TCalculator test;
	test.SetInf("(())");
	EXPECT_EQ(true, test.CheckBrackets());
}

TEST(TCalculator, check_brackets_3_true)
{
	TCalculator test;
	test.SetInf("()()");
	EXPECT_EQ(true, test.CheckBrackets());
}

TEST(TCalculator, check_brackets_4_true)
{
	TCalculator test;
	test.SetInf("(()())");
	EXPECT_EQ(true, test.CheckBrackets());
}

TEST(TCalculator, check_brakets_1_false)
{
	TCalculator test;
	test.SetInf("(");
	EXPECT_EQ(false, test.CheckBrackets());
}
TEST(TCalculator, check_brakets_2_false)
{
	TCalculator test;
	test.SetInf(")");
	EXPECT_EQ(false, test.CheckBrackets());
}
TEST(TCalculator, check_brakets_3_false)
{
	TCalculator test;
	test.SetInf("(()");
	EXPECT_EQ(false, test.CheckBrackets());
}
TEST(TCalculator, check_brakets_4_false)
{
	TCalculator test;
	test.SetInf("())");
	EXPECT_EQ(false, test.CheckBrackets());
}
TEST(TCalculator, check_brakets_5_false)
{
	TCalculator test;
	test.SetInf("()(");
	EXPECT_EQ(false, test.CheckBrackets());
}
TEST(TCalculator, check_brakets_6_false)
{
	TCalculator test;
	test.SetInf("((()");
	EXPECT_EQ(false, test.CheckBrackets());
}
TEST(TCalculator, check_brakets_7_false)
{
	TCalculator test;
	test.SetInf("(()))");
	EXPECT_EQ(false, test.CheckBrackets());
}

TEST(TCalculator, check_empty_string)
{
	TCalculator test;
	EXPECT_ANY_THROW(test.CheckBrackets());
}
TEST(TCalculator, check_operator_1_true)
{
	TCalculator test;
	test.SetInf("5+7");
	EXPECT_EQ(true, test.CheckOperator());
}
TEST(TCalculator, check_operator_2_true)
{
	TCalculator test;
	test.SetInf("(2+2)*2");
	EXPECT_EQ(true, test.CheckOperator());
}
TEST(TCalculator, check_operator_3_true)
{
	TCalculator test;
	test.SetInf("(2+2)*1-(1/2)");
	EXPECT_EQ(true, test.CheckOperator());
}

TEST(TCalculator, check_operator_1_false)
{
	TCalculator test;
	test.SetInf("5++5");
	EXPECT_EQ(false, test.CheckOperator());
}
TEST(TCalculator, check_operator_2_false)
{
	TCalculator test;
	test.SetInf("(2+2)+*5");
	EXPECT_EQ(false, test.CheckOperator());
}

TEST(TCalculator, check_operator_3_false)
{
	TCalculator test;
	test.SetInf("*25+55");
	EXPECT_EQ(false, test.CheckOperator());
}
TEST(TCalculator, check_operator_4_false)
{
	TCalculator test;
	test.SetInf("5568-468+");
	EXPECT_EQ(false, test.CheckOperator());
}

TEST(TCalculator, simple_ex_plus)
{
	TCalculator test;
	test.SetInf("5+5");
	test.ToPost();
	EXPECT_EQ("5 5+", test.GetPost());
	EXPECT_EQ(10, test.Calcucate());
}

TEST(TCalculator, simple_ex_minus)
{
	TCalculator test;
	test.SetInf("5-5");
	test.ToPost();
	EXPECT_EQ("5 5-", test.GetPost());
	EXPECT_EQ(0, test.Calcucate());
}
TEST(TCalculator, simple_ex_multiplication)
{
	TCalculator test;
	test.SetInf("5*5");
	test.ToPost();
	EXPECT_EQ("5 5*", test.GetPost());
	EXPECT_EQ(25, test.Calcucate());
}
TEST(TCalculator, simple_ex_division)
{
	TCalculator test;
	test.SetInf("2/5");
	test.ToPost();
	EXPECT_EQ("2 5/", test.GetPost());
	EXPECT_EQ(0.4, test.Calcucate());

}
TEST(TCalculator, simple_ex_degree)
{
	TCalculator test;
	test.SetInf("2^3");
	test.ToPost();
	EXPECT_EQ("2 3^", test.GetPost());
	EXPECT_EQ(8, test.Calcucate());
}
TEST(TCalculator, ex_1)
{
	TCalculator test;
	test.SetInf("(5+5)*2");
	test.ToPost();
	EXPECT_EQ("5 5+ 2*", test.GetPost());
	EXPECT_EQ(20, test.Calcucate());
}

TEST(TCalculator, ex_2)
{
	TCalculator test;
	test.SetInf("2/(2+2)+2");
	test.ToPost();
	EXPECT_EQ("2 2 2+ /2+", test.GetPost());
	EXPECT_EQ(2.5, test.Calcucate());
}
TEST(TCalculator, ex_3)
{
	TCalculator test;
	test.SetInf("1/(1+1)^2+2");
	test.ToPost();
	EXPECT_EQ("1 1 1+ 2 ^/2+", test.GetPost());
	EXPECT_EQ(2.25, test.Calcucate());
}

TEST(TCalculator, ex_4)
{
	TCalculator test;
	test.SetInf("(5+5)/20*2^5");
	test.ToPost();
	EXPECT_EQ("5 5+ 20 /2 5^*", test.GetPost());
	EXPECT_EQ(16, test.Calcucate());
}
TEST(TCalculator, ex_5)
{
	TCalculator test;
	test.SetInf("512-12^2/2");
	test.ToPost();
	EXPECT_EQ("512 12 2 ^2/-", test.GetPost());
	EXPECT_EQ(440,test.Calcucate());
}
