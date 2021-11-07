#include "Presets.h"

exprNode* Presets::linear()
{
	exprNode* x = new variableNode();
	return x;
}

exprNode* Presets::quadratic()
{
	exprNode* x = new variableNode();
	exprNode* n1 = new numNode(2);
	exprNode* root = new exponentNode(x, n1);
	return root;
}

exprNode* Presets::quintic()
{
	exprNode* x = new variableNode();
	exprNode* n1 = new numNode(3);
	exprNode* root = new exponentNode(x, n1);
	return root;
}

exprNode* Presets::sine()
{
	exprNode* x = new variableNode();
	exprNode* root = new sinNode(x);
	return root;
}

exprNode* Presets::exp()
{
	exprNode* n1 = new numNode(2);
	exprNode* x = new variableNode();
	exprNode* root = new exponentNode(n1, x);
	return root;
}

exprNode* Presets::sqrt()
{
	exprNode* v = new variableNode();
	exprNode* n1 = new numNode(1.0 / 2.0);
	exprNode* e = new exponentNode(v, n1);
	return e;
}
