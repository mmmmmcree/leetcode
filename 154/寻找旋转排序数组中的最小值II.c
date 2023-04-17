int findMin(int* nums, int numsSize){
    if(numsSize == 1 || nums[0] < nums[numsSize - 1]){return nums[0];}
    int i = 0;
    for(i; i < numsSize - 1; i++){
        if(nums[i] != nums[i + 1]){
            break;
        }
    }
    if(i == numsSize){return nums[0];}
    int left = i, right = numsSize - 1, mid = (left + right) / 2;
    while(nums[mid] <= nums[mid + 1]){
        if(nums[mid] > nums[0]){left = mid + 1;}
        else{right = mid;}
        mid = (left + right) / 2;
    }
    return nums[mid + 1];
}