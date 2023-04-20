int findMax(Node* root) {
    if(root == NULL) {
        return -1;
    }
    while(root->right != NULL) {
        root = root->right;
    }
    return root->data;
}