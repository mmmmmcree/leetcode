# include<stdio.h>
# include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int _max(int a, int b){
    return a > b? a: b;
}

int maxDepth(struct TreeNode* root){
    int max_depth;
    if(root != NULL){
        max_depth = 1 + _max(maxDepth(root->left), maxDepth(root->right));
    }
    else{
        max_depth = 0;
    }
    return max_depth;
}