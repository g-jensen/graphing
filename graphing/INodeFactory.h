#pragma once

#include "Nodes.h"

class INodeFactory
{
public:
	virtual exprNode* execute() = 0;
};

