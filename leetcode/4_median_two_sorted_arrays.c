// 4. Median of Two Sorted Arrays

// Example 1:

// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0

// Example 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5


double getMedian(int *nums, int start, int end){
    int length = end - start +1;
    if (length%2 != 0){
        return (double)(nums[start + length/2]);
    }else{
        return (double)(nums[start + length/2 - 1] + nums[start + length/2])/2;
    }    
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i1 = 0;
    int i2 = nums1Size -1;
    int j1 = 0;
    int j2 = nums2Size - 1;
    
    if(nums1Size == 0 && nums2Size == 0){ return 0.0;}
    else if(nums1Size == 0){
        return getMedian(nums2,j1,j2);
    }else if (nums2Size == 0){
        return getMedian(nums1,i1,i2);
    }
    
    while(1){
        // printf("%d : %d\n",i1,i2);
        // printf("%d : %d\n",j1,j2);
        double m1 = getMedian(nums1, i1, i2);
        double m2 = getMedian(nums2, j1, j2);
        // printf("%f : %f\n",m1,m2);
        int size1 = i2-i1+1;
        int size2 = j2-j1+1;        
        
        if (m1 == m2) {
            return m1;
        } else if (size1 + size2 <= 4){   
            // printf("%d\n",(nums1[i1]>nums2[j1]?nums1[i1]:nums2[j1]));
            // printf("%d\n",(nums1[i2]<nums2[j2]?nums1[i2]:nums2[j2]));
            return (double)((nums1[i1]>nums2[j1]?nums1[i1]:nums2[j1])+(nums1[i2]<nums2[j2]?nums1[i2]:nums2[j2]))/2;
        }     
        
        if (m1 > m2){
            i2 = i1 + size1/2;
            j1 = j1 + size2/2;
        }else if(m1<m2){
            i1 = i1 + size1/2;
            j2 = j1 + size2/2;
        }
        
    }
    
    return ;
    
}