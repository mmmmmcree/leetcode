# include<stdio.h>
# include<stdlib.h>

# define SIZE 5
// realloc他妈的会超时，只能在创建时就取numsSize*numsSize的大空间
int cmp(const void* a, const void* b){
    int *_a = (int*)(a), *_b = (int*)(b);
    return *_a < *_b? -1: *_a == *_b? 0: 1;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int **res = (int**)malloc(sizeof(int*)); 
    
    int index = 0;
    while (index < numsSize - 2 && nums[index] <=0)
    {
        int head = index + 1, tail = numsSize - 1;
        while (head < tail)
        {
            if (nums[index] + nums[head] + nums[tail] > 0)
                tail--;
            else if(nums[index] + nums[head] + nums[tail] < 0)
                head++;
            else
            {
                res = realloc(res, (*returnSize + 1) * sizeof(int*));
                res[*returnSize] = (int*)malloc(sizeof(int) * 3);
                res[*returnSize][0] = nums[index];
                res[*returnSize][1] = nums[head];
                res[*returnSize][2] = nums[tail];
                (*returnSize)++;
                head++;
                tail--;
                while (head < tail && nums[head] == nums[head - 1])
                    head++;
                while (head < tail && nums[tail] == nums[tail + 1])
                    tail--;
            }
        }
        if (index + 1 < numsSize)
        {
            index++;
            while (index < numsSize && nums[index] == nums[index - 1])
                index++;
        }
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (size_t i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = 3;
    }
    return res;
}

void main(){
    int nums[SIZE] = {-2, 0, 1, 1, 2}, *returnSize = (int*)malloc(sizeof(int)), *returnColumnSizes = (int*)malloc(sizeof(int));
    int** res = threeSum(nums, SIZE, returnSize, &returnColumnSizes);
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%3d", nums[i]);
    }
    
    for (size_t i = 0; i < *returnSize; i++)
    {
        printf("\n");
        for (size_t j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%3d", res[i][j]);
        }
    }
}