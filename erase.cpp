#include <stdlib.h>
#include <stdio.h>
#include <iostream>

struct Node 
{
    int value;
    bool is_black;
    Node* left;
    Node* right;
    Node* parent;
};

Node* max_tree(Node* tree)
{
    if (tree == nullptr)
    {
        return 0;
    }
    while (tree->right != nullptr)
    {
        tree = tree->right;
    }
    return tree;
}

Node* brother(Node* node)
{
    if ((node == nullptr) or (node->parent == nullptr))
    {
        return nullptr;
    }
    if (node->parent->left == node)
    {
        return node->parent->right;
    }
    return node->parent->left;
}

Node* rotate_left(Node* node) 
{
    Node* rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;
    return rightChild;
}

Node* rotate_right(Node* node) 
{
    Node* leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;
    return leftChild;
}

void erase(Node* deleted)
{
    if ((deleted->right != nullptr) && (deleted->left != nullptr))
    {
        deleted->value = max_tree(deleted->left)->value;
        erase(max_tree(deleted->left));
    }

    if (deleted->is_black == false)
    {
        if(deleted->parent->left == deleted)
        {
            deleted->parent->left = nullptr;
        }
        else
        {
            deleted->parent->right = nullptr;
        }
        delete deleted;
    }

    if ((deleted->is_black == true) && (deleted->left != nullptr) && (deleted->left->is_black == false))
    {
        if (deleted->parent->left == deleted)
        {
            deleted->parent->left = deleted->left;
        }
        else
        {
            deleted->parent->right = deleted->left;
        }
        deleted->left->parent = deleted->parent;
        deleted->left->is_black = true;
        delete deleted;
    }

    if ((deleted->is_black == true) && (deleted->left != nullptr) && (deleted->left->is_black == false))
    {
        if (deleted->parent != nullptr)
        {
            if (deleted->parent->left == deleted)
            {
                deleted->parent->left = deleted->left;
            }
            else
            {
                deleted->parent->right = deleted->left;
            }
        }
        deleted->left->parent = deleted->parent;
        deleted->left->is_black = true;
        delete deleted;
    }

    if ((deleted->is_black == true) && (deleted->left == nullptr) && (deleted->right == nullptr))
    {
        if (deleted->parent->right == deleted)
        {
            if (deleted->parent->is_black == false)
            {
                if (brother(deleted)->right->is_black == false)
                {
                    deleted->parent->is_black = true;
                    rotate_left(brother(deleted));
                    rotate_right(deleted->parent);
                }
                else if (brother(deleted)->left->is_black == false)
                {
                    deleted->parent->is_black = true;
                    rotate_right(brother(deleted));
                    rotate_right(deleted->parent);
                }
                else if (brother(deleted)->right->is_black == true && brother(deleted)->left->is_black == true)
                {
                    deleted->parent->is_black = true;
                    brother(deleted)->is_black = false;
                }
            }
            if (deleted->parent->is_black == true)
            {
                if (brother(deleted)->is_black == false)
                {
                    if (brother(deleted)->right->right->is_black == false)
                    {
                        brother(deleted)->right->right->is_black == true;
                        rotate_left(brother(deleted));
                        rotate_right(deleted->parent);                
                    }
                    if (brother(deleted)->right->left->is_black == false)
                    {
                        brother(deleted)->right->left->is_black == true;
                        rotate_left(brother(deleted));
                        rotate_right(deleted->parent);  
                    }
                    if (brother(deleted)->left->right->is_black == false)
                    {
                        brother(deleted)->left->right->is_black == true;
                        rotate_right(brother(deleted));
                        rotate_right(deleted->parent); 
                    }
                    if (brother(deleted)->left->left->is_black == false)
                    {
                        brother(deleted)->left->left->is_black == true;
                        rotate_right(brother(deleted));
                        rotate_right(deleted->parent);  
                    }  
                    if (brother(deleted)->right->right->is_black == true && brother(deleted)->right->left->is_black == true)
                    {
                        brother(deleted)->is_black = true;
                        brother(deleted)->right->is_black = false;
                        rotate_right(deleted->parent);
                    } 
                    else if (brother(deleted)->left->right->is_black == true && brother(deleted)->left->left->is_black == true) 
                    {
                        brother(deleted)->is_black = true;
                        brother(deleted)->left->is_black = false;
                        rotate_right(deleted->parent);
                    }
                }
                else 
                {
                    if (brother(deleted)->right->is_black = false)
                    {
                        brother(deleted)->right->is_black = true;
                        rotate_left(brother(deleted));
                        rotate_right(deleted->parent);
                    }
                    if ((brother(deleted)->left->is_black = false))
                    {
                        brother(deleted)->left->is_black = true;
                        rotate_left(brother(deleted));
                        rotate_right(deleted->parent);
                    }
                    else
                    {
                        brother(deleted)->is_black = false;
                        erase(deleted->parent);
                    }
                }
            }
        }
        else 
        {
            if (deleted->parent->is_black == false)
            {
                if (brother(deleted)->right->is_black == false)
                {
                    deleted->parent->is_black = true;
                    rotate_left(brother(deleted));
                    rotate_right(deleted->parent);
                }
                else if (brother(deleted)->left->is_black == false)
                {
                    deleted->parent->is_black = true;
                    rotate_right(brother(deleted));
                    rotate_right(deleted->parent);
                }
                else if (brother(deleted)->right->is_black == true && brother(deleted)->left->is_black == true)
                {
                    deleted->parent->is_black = true;
                    brother(deleted)->is_black = false;
                }
            }
            if (deleted->parent->is_black == true)
            {
                if (brother(deleted)->is_black == false)
                {
                    if (brother(deleted)->right->right->is_black == false)
                    {
                        brother(deleted)->right->right->is_black == true;
                        rotate_left(brother(deleted));
                        rotate_right(deleted->parent);                
                    }
                    if (brother(deleted)->right->left->is_black == false)
                    {
                        brother(deleted)->right->left->is_black == true;
                        rotate_left(brother(deleted));
                        rotate_right(deleted->parent);  
                    }
                    if (brother(deleted)->left->right->is_black == false)
                    {
                        brother(deleted)->left->right->is_black == true;
                        rotate_right(brother(deleted));
                        rotate_right(deleted->parent); 
                    }
                    if (brother(deleted)->left->left->is_black == false)
                    {
                        brother(deleted)->left->left->is_black == true;
                        rotate_right(brother(deleted));
                        rotate_right(deleted->parent);  
                    }  
                    if (brother(deleted)->right->right->is_black == true && brother(deleted)->right->left->is_black == true)
                    {
                        brother(deleted)->is_black = true;
                        brother(deleted)->right->is_black = false;
                        rotate_right(deleted->parent);
                    } 
                    else if (brother(deleted)->left->right->is_black == true && brother(deleted)->left->left->is_black == true) 
                    {
                        brother(deleted)->is_black = true;
                        brother(deleted)->left->is_black = false;
                        rotate_right(deleted->parent);
                    }
                }
                else 
                {
                    if (brother(deleted)->right->is_black = false)
                    {
                        brother(deleted)->right->is_black = true;
                        rotate_left(brother(deleted));
                        rotate_right(deleted->parent);
                    }
                    if ((brother(deleted)->left->is_black = false))
                    {
                        brother(deleted)->left->is_black = true;
                        rotate_left(brother(deleted));
                        rotate_right(deleted->parent);
                    }
                    else
                    {
                        brother(deleted)->is_black = false;
                        erase(deleted->parent);
                    }
                }
            }
        }
    }
}
