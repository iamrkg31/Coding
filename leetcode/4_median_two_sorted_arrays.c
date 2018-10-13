// 4. Median of Two Sorted Arrays

// Example 1:

// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0

// Example 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5


double getMedian(int *nums, int numsSize, begin){
    if (numsSize%2 != 0){
        return (double)(nums[numsSize/2 + begin]);
    }else{
        return (double)(nums[numsSize/2 - 1 + begin] + nums[numsSize/2 + begin])/2;
    }    
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int res = 0;
    int m1 = 0;
    int m2 = 0;
    
    int flag = 0;
    
    int i1 = 0;
    int i2 = nums1Size -1;
    int j1 = 0;
    int j2 = nums2Size - 1;
    
    if (nums1Size > nums2Size){
        flag = 1;
    }else if(nums1Size < nums2Size){
        flag = 2;
    }
    
    while(1){
        int size1 = i2-i1+1;
        int size2 = j2-j1+1;
        
        if (size1 == 2 && size2 == 2){
            if (nums1[])
        }
            
            
        m1 = getMedian(nums1, size1, i1);
        m2 = getMedian(nums2, size2, j1);
        
        if (m1 > m2){
            i2 = size1/2;
            j1 = size2/2;
        }else if(m1<m2){
            i1 = size1/2;
            j2 = size2/2;
        }else{
            res = m1;
            break;
        }
        
    }
    
    return res;
    
}