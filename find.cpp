#include <iostream>
using namespace std;

typedef enum { BLACK, RED } Color;

struct Tree
{
    Tree *left;        
    Tree *right;        
    Tree *parent;      
    Color color;            
    int data;                    
};

void insert(Tree* palm, int data)
{
    while((*palm).left != nullptr)
    {
        palm = palm->left;
    }
    (*palm).left = new Tree;
    *(*palm).left = {nullptr,nullptr,nullptr,BLACK, data};
}

Tree* search(Tree* node, int value) {
    if (node == nullptr || node->data == value) 
    {
        return node;
    }
    if (value < node->data) 
    {
        return search(node->left, value);
    }
    else {
        return search(node->right, value);
        }
}

int main(){
    Tree palm = {nullptr,nullptr,nullptr,BLACK, 0};
    insert(&palm, 0);
    palm.right = new Tree;
    *palm.right = {nullptr,nullptr,nullptr,BLACK, 0};
    (*palm.right).right = new Tree;
    *(*palm.right).right = {nullptr,nullptr,nullptr,BLACK, 7};
    int k=0;
    Tree* val = search(&palm, 7);
    if (val != nullptr) 
    {
        cout << "Found"<< endl;
    } else
     {
        cout << "Not found" << endl;
    }
}