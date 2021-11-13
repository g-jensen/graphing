#pragma once

#include "INodeFactory.h"

class AddNodeFactory: public INodeFactory
{
public:
	exprNode* execute();
};

