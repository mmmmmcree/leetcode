# include<stdio.h>
# include<stdlib.h>

int _max(int a, int b){
    return a > b? a: b;
}

int rob(int* nums, int numsSize){
    if(numsSize == 1){
        return nums[0];
    }
    else if(numsSize == 2){
        return _max(nums[0], nums[1]);
    }
    else if(numsSize == 3){
        return (_max(nums[2] + nums[0], nums[1]));
    }
    nums[2] = _max(nums[0], nums[1]);
    int i = 3;
    for(i; i < numsSize; i++){
        nums[i] += _max(nums[i-2], nums[i-3]);
    }
    return _max(nums[i], nums[i-1]);
}