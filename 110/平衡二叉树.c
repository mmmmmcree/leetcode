# include<stdio.h>
# include<stdlib.h>

# define bool int

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int _abs(int a){
    return a < 0? -a: a;
}

int _max(int a, int b){
    return a > b? a: b; 
}

int maxLevel(struct TreeNode* root){
    int level = 0;
    if(root){
        level += _max(maxLevel(root->left), maxLevel(root->right)) + 1;
    }
    return level;
}

bool iB(struct TreeNode* root){
    if(!root){return 1;}
    return _abs(maxLevel(root->left) - maxLevel(root->right)) > 1? 0: 1;
}

bool isBalanced(struct TreeNode* root){
    if(!root){return 1;}
    else{
        return iB(root) && isBalanced(root->left) && isBalanced(root->right);
    }
}