# include<stdio.h>
# include<stdlib.h>

# define bool int

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int inorder_traverse(struct TreeNode *tnode, int *pre, int *i){
    if (tnode == NULL){return 1;}
    else{
        int a = inorder_traverse(tnode->left, pre, i);
        if((*i)++ >= 1 && *pre >= tnode->val){return 0;}
        *pre = tnode->val;
        int b = inorder_traverse(tnode->right, pre, i);
        return a && b;
    }
} 

bool isValidBST(struct TreeNode* root){
    int pre, i = 0;
    return inorder_traverse(root, &pre, &i);
}