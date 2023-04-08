# include<stdio.h>
# include<stdlib.h>
/*
偷来的,桶排序。
时间超过100,为啥啊，for1000次了都
*/
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int* rearr = (int*)malloc(sizeof(int)*(nums1Size>nums2Size?nums2Size:nums1Size));
    int a[1001] = {0};
    int b[1001] = {0};
    *returnSize = 0;
    for(int i = 0; i<nums1Size; i++)
    {
        a[nums1[i]]++;
    }
    for(int i = 0; i<nums2Size; i++)
    {
        b[nums2[i]]++;
    }
    for(int i = 0; i<1001; i++)
    {
        if(a[i]>0&&b[i]>0)
        {
            int n = (a[i]>b[i])?b[i]:a[i];
            for(int j = 0; j<n ;j++)
            {
                rearr[(*returnSize)++] = i;
            }
        }
    }
    return rearr;
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