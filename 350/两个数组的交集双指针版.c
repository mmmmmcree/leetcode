# include<stdio.h>
# include<stdlib.h>
# include<math.h>
// 偷来的双指针版，效率跟我写的差不多，白写了，当作学一下qsort吧
int compare(void const* _a, void const* _b){
    int *a = (int*)_a, *b = (int*)_b;
    return *a == *b? 0 : *a < *b? -1 : 1;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = 0;
    int *intersect = (int*)malloc(sizeof(int) * (int)fmin(nums1Size, nums2Size));
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    int index1 = 0, index2 = 0;
    while (index1 < nums1Size && index2 < nums2Size){
        if (nums1[index1] < nums2[index2]){
            ++index1;
        }
        else if (nums2[index2] < nums1[index1]){
            ++index2;
        }
        else{
            intersect[(*returnSize)++] = nums1[index1];
            ++index1;
            ++index2;
        }
    }
    return intersect;
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