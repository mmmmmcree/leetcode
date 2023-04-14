# include<stdio.h>
# include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val){
    while(root != NULL){
        if(val < root->val){root = root->left;}
        else if(val > root->val){root = root->right;}
        else{break;}
    }
    return root;
}