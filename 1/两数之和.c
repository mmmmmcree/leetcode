# include<stdio.h>
# include<stdlib.h>
#include<string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *res = (int*)malloc(sizeof(int) * (*returnSize));
    for (size_t i = 0; i < numsSize; i++)
    {
        for (size_t j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
}

void main(){
    int a[4] = {-3, 4, 3, 1}, target = 0, *returnSize = (int*)malloc(sizeof(int));
    int *res = twoSum(a, 4, target, returnSize);
    for (size_t i = 0; i < 2; i++)
    {
        printf("%3d", res[i]);
    }
    

}