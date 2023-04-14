# include<stdio.h>
# include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0, *returnColumnSizes = (int*)malloc(sizeof(int));
    int **lists = (int**)malloc(sizeof(int*) * 1);
    int head = 0, tail = 0;
    struct TreeNode *a[2000];
    if(root != NULL){
        a[tail++] = root;
    }
    while(head < tail){
        lists = (int**)realloc(lists, sizeof(int*) * (*returnSize + 1));
        *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));
        int len = tail - head;
        (*returnColumnSizes)[*returnSize] = len;
        int *list = (int*)malloc(sizeof(int) * len);
        for(int i = 0; i < len; i++){
            list[i] = a[head]->val;
            if(a[head]->left != NULL){a[tail++] = a[head]->left;}
            if(a[head]->right != NULL){a[tail++] = a[head]->right;}
            head++;
        }
        lists[(*returnSize)++] = list;
    }
    return lists;
}