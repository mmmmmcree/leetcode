int singleNumber(int* nums, int numsSize){
    int res = 0;
    for(int i = 0; i < 32; i++){
        int total = 0;
        for(int j = 0; j < numsSize; j++){
            total += (nums[j] >> i ) & 1;
        }
        if(total % 3){
            res |= 1u << i;
        }
    }
    return res;
}