# include<stdio.h>
# include<stdlib.h>
/*
执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗：5.6 MB, 在所有 C 提交中击败了97.77%的用户
*/
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int curse = 1, tail = digitsSize, *res = (int*)malloc(sizeof(int) * (digitsSize  + 1));
    *returnSize = 0;
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (digits[i] + curse == 10)
        {
            (*returnSize)++;
            res[tail--] = 0;
            curse = 1;
        }
        else
        {
            (*returnSize)++;
            res[tail--] = digits[i] + curse;
            curse = 0;
        }
    }
    if (curse == 1)
    {
        (*returnSize)++;
        res[0] = 1;
        return res;
    }
    else
    {
        return res + 1;
    }
}

void main(){
    int a[10] = {9,8,7,6,5,4,3,2,1,0};
    int *returnSize;
    int *res = plusOne(a, 10, returnSize);
    for (size_t i = 0; i < 10; i++)
    {
        printf("%3d", res[i]);
    }
    
}