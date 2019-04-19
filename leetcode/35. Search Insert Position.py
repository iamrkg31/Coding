class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l=0
        r = len(nums)-1
        while(l<=r):
            index = int((r-l + 1)/2)
            index = l + index
            print(nums[index])
            if nums[index] == target:
                return index
            elif nums[index] > target:
                print(1)
                r = index -1
            elif nums[index] < target:
                print(2)
                l = index + 1
            if(l>r):
                if r < 0:
                    return 0
                else:
                    return index+1