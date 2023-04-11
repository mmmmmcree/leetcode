# include<stdio.h>
# include<stdlib.h>
//  第一次实现，可行，但是递归会超出力扣的时间限制。
# define SIZE 20

int _max(int a, int b){
    return a > b? a: b;
}

int lengthOfLIS_recur(int* nums, int numsSize){
    int max = 1;
    for(int j = 1; j < numsSize; j++){
        int p = 1;
        if(nums[0] < nums[j]){
            p += lengthOfLIS_recur(nums + j, numsSize - j);
        }
        if(p > max){max = p;}
    }
    return max;    
}

int lengthOfLIS(int* nums, int numsSize){
    int max = 1;
    for(int i = 0; i < numsSize; i++){
        max = _max(max, lengthOfLIS_recur(nums + i, numsSize - i));
    }
    return max;
}

void main(){
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 5, 14, 15, 16, 17, 18, 19, 20};
    printf("%d", lengthOfLIS(a, SIZE));
}