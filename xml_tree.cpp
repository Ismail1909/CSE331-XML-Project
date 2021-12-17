#include"xml_tree.h"
/* Tree Node Class */

    tnode::tnode(int data)
    {
        this->data = data;
    }
    tnode *  tnode:: getChild(int index)
    {
        return children[index];
    }
    void tnode:: setChild(tnode *node)
    {
        children.push_back(node);
    }
    int tnode:: getSize()
    {
        return children.size();
    }
    int tnode:: getData(tnode *node)
    {
        return node->data;
    }

    tree::tree()
    {
        root = nullptr;
    };
    void tree:: setRoot(tnode *root)
    {
        this->root = root;
    }