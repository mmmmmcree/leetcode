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
    if(!root){return 0;}
    int level = 0;
    int left_level = maxLevel(root->left), right_level = maxLevel(root->right);
    if(left_level == -1 || right_level == -1 || _abs(left_level - right_level) > 1){
        return -1;
    }
    return _max(left_level, right_level) + 1;
}

bool isBalanced(struct TreeNode* root){
    return maxLevel >= 0;
}