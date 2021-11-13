#include "AddNodeFactory.h"

exprNode* AddNodeFactory::execute()
{
    exprNode* output = new addNode();
    return output;
}
