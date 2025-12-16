/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void merge(int *nums , int left , int mid , int right){
    int i = left;
    int j = mid+1;
    int k = 0;

    int *temp = (int *)malloc(sizeof(int) * (right - left + 1));

    while(i <= mid && j <= right){
        if(nums[i] <= nums[j]){
            temp[k] = nums[i];
            i++;
            k++;
        }
        else{
            temp[k] = nums[j];
            k++;
            j++;
        }
    }

    while(i <= mid){
        temp[k] = nums[i];
        k++;
        i++;
    }

    while(j <= right){
        temp[k] = nums[j];
        j++;
        k++;
    }

    for(int i = 0 ; i < k ; i++){
        nums[left + i] = temp[i];
    }
    free(temp);
}



void mergeSort(int *nums , int left, int right){
    if(left < right){
        int mid = left + ((right - left) / 2);
        mergeSort(nums , left , mid);
        mergeSort(nums , mid+1 , right);
        merge(nums , left , mid , right); 
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    mergeSort(nums , 0 , numsSize-1);
    return nums;
}