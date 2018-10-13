#include <stdio.h>

double getMedian(int *nums, int numsSize){
    if (numsSize%2 != 0){
        return (double)(nums[numsSize/2]);
    }else{
        return (double)(nums[numsSize/2 - 1] + nums[numsSize/2])/2;
    }    
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int res = 0;
    double m1 = 0;
    double m2 = 0;
    
    int i1 = 0;
    int i2 = nums1Size -1;
    int j1 = 0;
    int j2 = nums2Size - 1;
    
    while(i1 < nums1Size && i2 >= 0 && j1 < nums2Size && j2 >= 0){
        int size1 = i2-i1+1;
        int size2 = j2-j1+1;

        m1 = getMedian(nums1, size1);
        m2 = getMedian(nums2, size2);
        
        printf("m1: %f\n", m1);
        printf("m2 : %f\n", m2);

        if (m1 > m2){
            i2 = size1/2;
            j1 = size2/2;
        }else if(m1 < m2){
            i1 = size1/2;
            j2 = size2/2;
        }else{
            res = m1;
            break;
        }
    }
    
    return res;
    
}

int main(){

    int a[2] = {1,2};
    int b[2] = {3,4};

    printf("%f\n",findMedianSortedArrays(a,2,b,2));

    return 0;
}