#pragma once

#include <string>
//#include <iostream>
#include <stack>

class PostFix
{
public:
	static int prec(char c);
	static std::string InfixToPostfix(std::string s);
};

