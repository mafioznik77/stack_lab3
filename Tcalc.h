#include "tStack.h"
#include <string>

using namespace std;

class TCalculator
{
	string inf;
	string post;

	TStack<char> Stop;
	TStack<double> StrNum;

public:
	void SetInf(string str);
	string GetPost();
	int StCheck();
	int Prty(char c);
	void ToPost();
	double Calcucate();
};


void TCalculator::SetInf(string str)
{
	inf = str;
}

string TCalculator::GetPost()
{
	return post;
}

int TCalculator::StCheck()
{
	Stop.Clr();

	for (int i = 0; i < inf.size(); i++)
	{
		if (inf[i] == '(') Stop.Push('(');
		if (inf[i] == ')')
		{
			if (Stop.IsEmpty())
				return 0;
			Stop.Pop();
		}
	}
	if (Stop.IsEmpty()) 
		return 1;
	else 
		return 0;
}

int TCalculator::Prty(char c)
{
	switch (c)
	{
	case '(': 
		return 0;
	case '+':
		return 1;
	case '-':
		return 1;
	case '*': 
		return 2;
	case '/': 
		return 2;
	case '^':
		return 3;
	}
}

void TCalculator::ToPost()
{
	if (!StCheck())
		throw - 1;

	post = "";
	Stop.Clr();

	string buf = '(' + inf + ')';

	for (int i = 0; i < buf.size(); i++)
	{
		if (buf[i] == '(') Stop.Push('(');
		if (((buf[i] >= '0'&& buf[i] <= '9')) || buf[i] == '.') post += buf[i];
		if (buf[i] == ')')
		{
			char el = Stop.Pop();

			while (el != '(')
			{
				post += el;
				el = Stop.Pop();
			}
		}
		if (buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/' || buf[i] == '^')
		{
			post += " ";

			while (Prty(buf[i]) <= Prty(Stop.Top()))
			{
				post += Stop.Pop();
			}
			Stop.Push(buf[i]);
		}
	}
}

double TCalculator::Calcucate()
{
	StrNum.Clr();

	for (int i = 0; i < post.size(); i++)
	{
		if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^')
		{
			double op1, op2, res;

			op2 = StrNum.Pop();
			op1 = StrNum.Pop();

			switch (post[i])
			{
			case '+': res = op1 + op2; 
				break;
			case '-': res = op1 - op2; 
				break;
			case '*': res = op1 * op2; 
				break;
			case '/': res = op1 / op2;
				break;
			case '^': res = pow(op1, op2); 
				break;
			}
			StrNum.Push(res);
		}

		if (post[i] >= '0' && post[i] <= '9' || post[i] == '.')
		{
			char *tmp;
			double res = strtod(&post[i], &tmp);
			int j = tmp - &post[i];

			i += j - 1;
			StrNum.Push(res);
		}
	}
	return StrNum.Pop();
}
