#ifndef ASTNODE_H
#define ASTNODE_H

#include <iostream>

#include "astdefines.h"

using namespace std;

class ASTNode
{
public:
    ASTNode();
    ~ASTNode();

    ASTNodeType getNodeType() const;
    void setNodeType(const ASTNodeType &value);

    int getNodeValue() const;
    void setNodeValue(int value);

    ASTNode *getLeftChild() const;
    void setLeftChild(ASTNode *value);

    ASTNode *getRightChild() const;
    void setRightChild(ASTNode *value);

    void print2DUtil(ASTNode* root, int space);
    void print2D();

private:
    ASTNodeType nodeType;
    int nodeValue;
    ASTNode* leftChild;
    ASTNode* rightChild;
};

#endif // ASTNODE_H
