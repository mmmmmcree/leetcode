# include<stdio.h>
# include<stdlib.h>
/*
执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗：5.7 MB, 在所有 C 提交中击败了97.79%的用户
*/
int removeElement(int* nums, int numsSize, int val){
    int head = 0, tail = numsSize - 1;
    while (head <= tail)
    {
        for (head; head <= tail && nums[head] != val; head++);
        for (tail; head <= tail && nums[tail] == val; tail--);
        if (head < numsSize && head < tail)
        {
            // 交换的逻辑，但不用交换函数
            nums[head] = nums[tail];
            nums[tail] = val;
        }
    }
    return head;
}

void main(){
    int a[4] = {3, 2, 2, 3};
    int x = removeElement(a, 4, 3);
    for (size_t i = 0; i < 4; i++)
    {
        printf("%3d", a[i]);
    }
    printf("\n%d", x);
}