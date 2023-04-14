# include<stdio.h>
# include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int is_all_zeros(struct TreeNode* root){
    if(!root){return 1;}
    else if(root->val == 1){return 0;}
    return root->val == 0 && is_all_zeros(root->left) && is_all_zeros(root->right);
}

struct TreeNode* pruneTree(struct TreeNode* root){
    if(!root || is_all_zeros(root)){return NULL;}
    else{
        pruneTree(root->left);
        pruneTree(root->right);
        root->left = is_all_zeros(root->left)? NULL: root->left;
        root->right = is_all_zeros(root->right)? NULL: root->right;
    }
    return root;
}