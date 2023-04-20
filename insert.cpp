#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

struct Node 
{
    int val;
    bool is_black;
    Node* left;
    Node* right;
    Node* parent;
};

Node* create_node(int val) 
{
    Node* node = new Node();
    node->val = val;
    node->is_black = false;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    return node;
}

Node* find(Node*& root, int key)
{
    Node* parent = nullptr;
    Node* curr = root;
    while (curr != nullptr) 
    {
        parent = curr;
        if (key < curr->val) 
        {
            curr = curr->left;
        } 
        else if (key > curr->val)
        {
            curr = curr->right;
        }
        else
        {
            parent = curr;
            break;
        }
    }
}

void insert_node(Node*& root, int key) 
{
    if (root == nullptr) 
    {
        root = create_node(key);
        root->is_black = true;
        return;
    }

    Node* parent = nullptr;
    Node* curr = root;
    while (curr != nullptr) 
    {
        parent = curr;
        if (key < curr->val) 
        {
            curr = curr->left;
        } 
        else if (key > curr->val)
        {
            curr = curr->right;
        }
        else
        {
            parent = curr;
            break;
        }
    }

    Node* node = parent;
    node->parent = parent;
    if (node->val < parent->val) 
    {
        parent->left = node;
    } 
    else 
    {
        parent->right = node;
    }
    node->is_black = false;

    while (node != root && !node->parent->is_black) 
    {
        if (node->parent == node->parent->parent->left) 
        {
            Node* uncle = node->parent->parent->right;
            if (uncle != nullptr && !uncle->is_black) 
            {
                node->parent->is_black = true;
                uncle->is_black = true;
                node->parent->parent->is_black = false;
                node = node->parent->parent;
            } 
            else 
            {
                if (node == node->parent->right) 
                {
                    node = node->parent;
                    rotate_left(root, node);
                }
                node->parent->is_black = true;
                node->parent->parent->is_black = false;
                rotate_right(root, node->parent->parent);
            }
        } 
        else 
        {
            Node* uncle = node->parent->parent->left;
            if (uncle != nullptr && !uncle->is_black) 
            {
                node->parent->is_black = true;
                uncle->is_black = true;
                node->parent->parent->is_black = false;
                node = node->parent->parent;
            }
            else 
            {
                if (node == node->parent->left) 
                {
                    node = node->parent;
                    rotate_right(root, node);
                }
                node->parent->is_black = true;
                node->parent->parent->is_black = false;
                rotate_left(root, node->parent->parent);
            }
        }
    }
    root->is_black = true;
}

void rotate_left(Node*& root, Node* node) 
{
    Node* right_child = node->right;
    node->right = right_child->left;
    if (right_child->left != nullptr) 
    {
        right_child->left->parent = node;
    }
    right_child->parent = node->parent;
    if (node->parent == nullptr) 
    {
        root = right_child;
    } 
    else if (node == node->parent->left) 
    {
        node->parent->left = right_child;
    } 
    else 
    {
        node->parent->right = right_child;
    }
    right_child->left = node;
    node->parent = right_child;
}

void rotate_right(Node*& root, Node* node) 
{
    Node* left_child = node->left;
    node->left = left_child->right;
    if (left_child->right != nullptr) 
    {
        left_child->right->parent = node;
    }
    left_child->parent = node->parent;
    if (node->parent == nullptr) 
    {
        root = left_child;
    } 
    else if (node == node->parent->right) 
    {
        node->parent->right = left_child;
    } 
    else 
    {
        node->parent->left = left_child;
    }
    left_child->right = node;
    node->parent = left_child;
}

void print_tree(Node* tree, int padding = 0) 
{
    if (tree != nullptr) 
    {
        cout << std::setw(padding) << ' ' << std::setw(0) << " ["<< tree->val << "] " << endl;
        padding += 2;
        print_tree(tree->left, padding); 
        print_tree(tree->right, padding); 
    }
}
