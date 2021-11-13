#include "MultNodeFactory.h"

exprNode* MultNodeFactory::execute()
{
    exprNode* output = new multNode();
    return output;
}
