#include "DivideNodeFactory.h"

exprNode* DivideNodeFactory::execute()
{
    exprNode* output = new divideNode;
    return output;
}
