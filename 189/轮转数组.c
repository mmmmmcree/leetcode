# include<stdio.h>
# include<stdlib.h>
/*
执行用时：104 ms, 在所有 C 提交中击败了86.24%的用户
内存消耗：22.1 MB, 在所有 C 提交中击败了8.09%的用户
*/
void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;
    if (numsSize == 1 || k == 0)
    {
        return;
    }
    int *temp_array = (int*)malloc(sizeof(int) * numsSize);
    size_t index = 0;
    for (size_t i = numsSize - k; i < numsSize; i++)
    {
        temp_array[index++] = nums[i];
    }
    for (size_t i = 0; i < numsSize - k; i++)
    {
        temp_array[index++] = nums[i];
    }
    for (size_t i = 0; i < numsSize; i++)
    {
        nums[i] = temp_array[i];
    }
    free(temp_array);
}

void main(){
    int array[2] = {1, 2};
    rotate(array, 2, 3);
    for (size_t i = 0; i < 2; i++)
    {
        printf("%3d", array[i]);
    }
    
}