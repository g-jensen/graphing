#include "SubtractNodeFactory.h"

exprNode* SubtractNodeFactory::execute()
{
    exprNode* output = new subtractNode();
    return output;
}
