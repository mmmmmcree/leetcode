# include<stdio.h>
# include<stdlib.h>

int _max(int a, int b){
    return a > b? a: b;
}

int lengthOfLIS(int* nums, int numsSize){
    int max = 1;
    int *dp = (int*)malloc(sizeof(int) * numsSize);
    dp[0] = 1;
    for(int i = 1; i < numsSize; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = _max(dp[j] + 1, dp[i]);
            }
        }
        max = _max(max, dp[i]);
    }
    return max;
}
