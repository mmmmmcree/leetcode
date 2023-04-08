# include<stdio.h>
# include<stdlib.h>
/*
执行用时：8 ms, 在所有 C 提交中击败了37.79%的用户
内存消耗：6 MB, 在所有 C 提交中击败了84.82%的用户
*/
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = 0;
    if (nums1Size < nums2Size){
        int *res = (int*)malloc(sizeof(int) * nums1Size);
        for (size_t i = 0; i < nums1Size; i++){
            for (size_t j = 0; j < nums2Size; j++){
                if (nums1[i] == nums2[j]){
                    res[(*returnSize)++] = nums1[i];
                    nums2[j] = -1; //第一次相等之后把长数组中的这个数改为-1, 下一次就会跳过这个数, 去比较后面的数了
                    break;
                }
            }
        }
        return res;
    }
    else{
        int *res = (int*)malloc(sizeof(int) * nums1Size);
        for (size_t i = 0; i < nums2Size; i++){
            for (size_t j = 0; j < nums1Size; j++){
                if (nums1[j] == nums2[i]){
                    res[(*returnSize)++] = nums2[i];
                    nums1[j] = -1;
                    break;
                }
            }
        }
        return res;
    }  
}

void main(){
    int a[6] = {4, 7, 9, 7, 6, 7};
    int b[9] = {5,0,0,6,1,6,2,2,4};
    int * returnSize;
    int *in = intersect(a, 6, b, 9, returnSize);
    printf("%d\n", *returnSize);
    for (size_t i = 0; i < *returnSize; i++)
    {
        printf("%d\t", in[i]);
    }
    
}