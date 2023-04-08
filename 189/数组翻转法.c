# include<stdio.h>
# include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void array_reverse(int *array, int start, int end){
    while (start < end)
    {
        swap(&array[start++], &array[end--]);
    }
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    array_reverse(nums, 0, numsSize - 1);
    array_reverse(nums, 0, k - 1);
    array_reverse(nums, k, numsSize - 1);
}

void main(){
    int array[2] = {1, 2};
    rotate(array, 2, 3);
    for (size_t i = 0; i < 2; i++)
    {
        printf("%3d", array[i]);
    }
    
}