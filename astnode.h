#ifndef ASTNODE_H
#define ASTNODE_H

#include "astdefines.h"

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

private:
    ASTNodeType nodeType;
    int nodeValue;
    ASTNode* leftChild;
    ASTNode* rightChild;
};

#endif // ASTNODE_H
