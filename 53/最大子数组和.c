# include<stdio.h>
# include<stdlib.h>

int _max(int a, int b, int c){
    return a > b? a > c? a: c: b > c? b: c;
}

int recur_maxSubArray(int *nums, int left, int right){
    if(left >= right){
        return nums[left];
    }
    int mid = (left + right) / 2;
    int max_left = recur_maxSubArray(nums, left, (right - left) % 2 == 1? mid: mid - 1);
    int max_right = recur_maxSubArray(nums, mid + 1, right);
    int num_mid = (right - left) % 2 == 1? 0: nums[mid];
    int sum_left = num_mid, sum_right = num_mid;
    int sum_left_max = sum_left, sum_right_max = sum_right;
    for(int i = (right - left) % 2 == 1? mid: mid - 1; i >= left; i--){
        sum_left += nums[i];
        if(sum_left > max_left){
            max_left = sum_left;
        }
        if(sum_left > sum_left_max){
            sum_left_max = sum_left;
        }
    }
    for(int i = mid + 1; i <= right; i++){
        sum_right += nums[i];
        if(sum_right > max_right){
            max_right = sum_right;
        }
        if(sum_right > sum_right_max){
            sum_right_max = sum_right;
        }
    }
    return _max(max_left, sum_left_max + sum_right_max - num_mid, max_right);
}

int maxSubArray(int* nums, int numsSize){
    int p = nums[0], flag = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0){
            return recur_maxSubArray(nums, 0, numsSize - 1);
        }
        else if (nums[i] > p){
            p = nums[i];
        }
    }
    return p;
}

void main(){
    int nums[] = {5,4,-1,7,8};
    printf("%d", maxSubArray(nums, 5));
}