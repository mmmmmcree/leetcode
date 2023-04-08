# include<stdio.h>
# include<stdlib.h>
//  一共需交换numsSize次，每次交换后current后移k位, 如果current回到起点，则起点后移一位, 重复交换
void swap(int *a, int *b){
    int temp = *a;
    *a = *b, *b = temp;
}

void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;
    if (k == 0)
        return;
    int temp = nums[0];
    size_t pre = 0;
    size_t current = k;
    for (size_t cnt = 0; cnt < numsSize; cnt++)
    {
        if (current != pre)
        {
            swap(&nums[current], &temp);
            current = (current + k) % numsSize;
        }
        else
        {
            swap(&nums[current], &temp);
            current = (current + k + 1) % numsSize;
            pre = (pre + 1) % numsSize;
            temp = nums[pre];
        }
    }
}

void main(){
    int array[6] = {1, 2, 3, 4, 5, 6};
    rotate(array, 6, 2);
    for (size_t i = 0; i < 6; i++)
    {
        printf("%3d", array[i]);
    }
    
}