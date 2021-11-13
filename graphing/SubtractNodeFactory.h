#pragma once

#include "INodeFactory.h"

class SubtractNodeFactory: public INodeFactory
{
public:
	exprNode* execute();
};

