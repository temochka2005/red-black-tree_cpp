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


int height(Tree* node) {
    if (node == nullptr) {
        return 0;
    }
    int height_left = height(node->left);
    int height_right = height(node->right);
    return max(height_left, height_right) + (node->color == BLACK ? 1 : 0);
}


int main(){
    Tree palm = {nullptr,nullptr,nullptr,BLACK, 0};
    insert(&palm, 0);
    palm.right = new Tree;
    *palm.right = {nullptr,nullptr,nullptr,BLACK, 0};
    (*palm.right).right = new Tree;
    *(*palm.right).right = {nullptr,nullptr,nullptr,BLACK, 0};
    cout << height(&palm);
}