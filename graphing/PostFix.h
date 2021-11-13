#pragma once

#include <string>
#include <stack>
#include <unordered_map>
#include "Nodes.h"
#include "NodeFactories.h"
#include <iostream>
#include <sstream>

class PostFix
{
public:
	static std::vector<std::string> TokenizeString(std::string s, char token);
	static std::unordered_map<std::string, INodeFactory*> tokens;
	static std::string RemoveSpace(std::string s);
	static int Prec(char c);
	static std::string InfixToPostfix(std::string s);
	static exprNode* PostfixToTree(std::string s);
};

