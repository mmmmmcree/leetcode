int missingNumber(int* nums, int numsSize){
    int res = (1 + numsSize) * numsSize / 2;
    for(int i = 0; i < numsSize; i++){
        res -= nums[i];
    }
    return res;
}