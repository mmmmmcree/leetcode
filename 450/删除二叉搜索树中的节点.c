# include<stdio.h>
# include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* get_minNode(struct TreeNode *root){
    while(root && root->left){
        root = root->left;
    }
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if(!root){return NULL;}
    else if(key < root->val){root->left = deleteNode(root->left, key);}
    else if(key > root->val){root->right = deleteNode(root->right, key);}
    else{
        if(!root->right){return root->left;}
        if(!root->left){return root->right;}
        struct TreeNode *p = get_minNode(root->right);
        p->left = root->left;
        root = root->right;
    }
    return root;
}