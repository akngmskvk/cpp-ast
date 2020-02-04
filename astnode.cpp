#include "astnode.h"

ASTNode::ASTNode()
{
    this->nodeType = Undefined;
    this->nodeValue = 0;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

ASTNode::~ASTNode()
{
    delete leftChild;
    delete rightChild;
}

ASTNodeType ASTNode::getNodeType() const
{
    return nodeType;
}

void ASTNode::setNodeType(const ASTNodeType &value)
{
    nodeType = value;
}

int ASTNode::getNodeValue() const
{
    return nodeValue;
}

void ASTNode::setNodeValue(int value)
{
    nodeValue = value;
}

ASTNode *ASTNode::getLeftChild() const
{
    return leftChild;
}

void ASTNode::setLeftChild(ASTNode *value)
{
    leftChild = value;
}

ASTNode *ASTNode::getRightChild() const
{
    return rightChild;
}

void ASTNode::setRightChild(ASTNode *value)
{
    rightChild = value;
}
