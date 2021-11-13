#pragma once

#include "INodeFactory.h"

class MultNodeFactory: public INodeFactory
{
public:
	exprNode* execute();
};

