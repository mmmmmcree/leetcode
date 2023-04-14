# include<stdio.h>
# include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode* root){
    int res = 0;
    if(!root){return res;}
    else{
        res = 1;
        res += countNodes(root->left);
        res += countNodes(root->right);
    }
    return  res;
}