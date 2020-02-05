#include "astnode.h"

#define COUNT 10

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

void ASTNode::print2DUtil(ASTNode *root, int space)
{
    // Base case
    if (root == nullptr)
    {
        return;
    }

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->getRightChild(), space);

    // Print current node after space
    cout << endl;
    for (int i = COUNT; i < space; i++)
    {
        cout << " ";
    }
    if (root->getNodeType() == NumberValue)
    {
        cout << root->getNodeValue() << endl;
    }
    else
    {
        switch (root->getNodeType()) {
        case OperatorPlus:
            cout << "+" << endl;
            break;
        case OperatorMinus:
            cout << "-" << endl;
            break;
        case OperatorMul:
            cout << "*" << endl;
            break;
        case OperatorDiv:
            cout << "/" << endl;
            break;
        default:
            break;
        }
    }

    // Process left child
    print2DUtil(root->getLeftChild(), space);
}

// Wrapper over print2DUtil()
void ASTNode::print2D()
{
    // Pass initial space count as 0
    print2DUtil(this, 0);
}
