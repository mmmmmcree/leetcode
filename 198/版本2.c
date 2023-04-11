# include<stdio.h>
# include<stdlib.h>

int _max(int a, int b){
    return a > b? a: b;
}

int rob(int* nums, int numsSize){
    if(numsSize == 1){
        return nums[0];
    }
    nums[1] = _max(nums[0], nums[1]);
    int i = 2;
    for(i; i < numsSize; i++){
        nums[i] = _max(nums[i-2] + nums[i], nums[i-1]);
    }
    return _max(nums[i-2], nums[i-1]);
}