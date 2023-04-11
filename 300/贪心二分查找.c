# include<stdio.h>
# include<stdlib.h>

typedef struct Array{
    int *a;
    int length;
}*Array;

Array create_array(int numsSize){
    Array array = (Array)malloc(sizeof(struct Array));
    array->a = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        array->a[i] = -1;
    }
    array->length = 0;
    return array;
}

int b_search(int *a, int numsSize, int num){
    int left = 0, right = numsSize - 1, mid;
    while(left < right){
        mid = (left + right) / 2;
        if(num > a[mid]){
            left = mid + 1;
        }
        else if(num < a[mid]){
            right = mid;
        }
        else{
            return mid;
        }
    }
    return left;
}

int lengthOfLIS(int* nums, int numsSize){
    Array array = create_array(numsSize);
    for(int i = 0; i < numsSize; i++){
        if(array->length == 0 || nums[i] > array->a[array->length - 1]){
            array->a[array->length++] = nums[i];
        }
        else{
            int replace_pos = b_search(array->a, array->length, nums[i]);
            array->a[replace_pos] = nums[i];
        }
    }
    return array->length;
}