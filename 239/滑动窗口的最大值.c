# include<stdio.h>
# include<stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *q = (int*)malloc(sizeof(int) * numsSize);
    int left = 0, right = 0;
    *returnSize = numsSize - k + 1;
    int *res_nums = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < k - 1; i++){
        while(left < right && nums[i] > nums[q[right - 1]]){right--;}
        q[right++] = i;
    }
    for(int i = k - 1; i < numsSize; i++){
        while(left < right && nums[i] > nums[q[right - 1]]){right--;}
        q[right++] = i;
        if(q[left] < i - k + 1){left++;}
        res_nums[i - k + 1] = nums[q[left]];
    }
    return res_nums;
}