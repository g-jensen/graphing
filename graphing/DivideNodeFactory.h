#pragma once

#include "INodeFactory.h"

class DivideNodeFactory: public INodeFactory
{
public:
	exprNode* execute();
};

