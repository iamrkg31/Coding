// 4. Median of Two Sorted Arrays

// Example 1:

// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0

// Example 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5


// make sure nums1Size <= nums2Size
double getMedian(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int x1,x2,y1,y2;
    int i1=0,i2=nums1Size;
    
    int odd = 0;
    if ((nums1Size+nums2Size)%2 != 0) odd = 1;
    
    int partition1, partition2;
    
    while(i1<=i2){
        
        partition1 = (i2+i1)/2;
        partition2 = (nums1Size+nums2Size+1)/2 - partition1;
        
        x1 = (partition1 == 0)?INT_MIN:nums1[partition1-1];
        x2 = (partition1 == nums1Size)?INT_MAX:nums1[partition1];
        
        y1 = (partition2 == 0)?INT_MIN:nums2[partition2-1];
        y2 = (partition2 == nums2Size)?INT_MAX:nums2[partition2];
        
        printf("%d:%d:%d:%d\n",x1,x2,y1,y2);
        
        if(x1<=y2 && y1<=x2){
            if (odd){
                return (x1>y1?x1:y1);
            }else{
                return (double)((x1>y1?x1:y1)+(x2<y2?x2:y2))/2;
            }
        }else if(x1>y2){
                i2 = partition1 - 1;                
        }else{           
                i1 = partition1 + 1;
        }
    }
    
    return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double res = 0;    
    
    if (nums1Size <= nums2Size){
        res = getMedian(nums1, nums1Size, nums2, nums2Size);
    }else{
        res = getMedian(nums2, nums2Size, nums1, nums1Size);
    }       
    
    return res;    
}