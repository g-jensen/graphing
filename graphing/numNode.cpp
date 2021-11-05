#include "numNode.h"

numNode::numNode() {

}

numNode::numNode(float val) : val(val) {

}

float numNode::eval() {
    return val;
}