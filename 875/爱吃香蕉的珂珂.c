int sum_time(int* piles, int pilesSize, int k){
    int sum = 0;
    for(int i; i < pilesSize; i++){
        if(piles[i] % k){sum += piles[i] / k + 1;}
        else{sum += piles[i] / k;}
    }
    return sum;
}

int max_in_nums(int *nums, int numsSize){
    int max = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max){max = nums[i];}
    }
    return max;
}

int minEatingSpeed(int* piles, int pilesSize, int h){
    int left = 1, right = max_in_nums(piles, pilesSize), mid;
    while(left < right){
        mid = (left + right) / 2;
        if(sum_time(piles, pilesSize, mid) <= h){right = mid;}
        else{left = mid + 1;}
    }
    return right;
}