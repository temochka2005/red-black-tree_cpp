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

void pre_order_traversal(Node* node) { 
    if (node != nullptr) { 
        cout << node->key << " "; 
        pre_order_traversal(node->left); 
        pre_order_traversal(node->right); 
    } 
}
Функция прямого обхода.
void in_order_traversal(Node* node) { 
    if (node != nullptr) { 
        in_order_traversal(node->left); 
        cout << node->key << " "; 
        in_order_traversal(node->right); 
    } 
}
Функция симметричного обхода.
void in_order_traversal(Node* node) {  
    if (node != nullptr) {  
        in_order_traversal(node->left); 
        in_order_traversal(node->right);  
        cout << node->key << " "; 
    }  
}