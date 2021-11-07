#pragma once

#include "Nodes.h"

class Presets
{
public:
	static exprNode* linear();
	static exprNode* quadratic();
	static exprNode* quintic();
	static exprNode* sine();
	static exprNode* exp();
	static exprNode* sqrt();
};

