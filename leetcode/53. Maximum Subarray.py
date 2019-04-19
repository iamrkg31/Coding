class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = -1 * sys.maxsize
        curr = 0
        for i in nums:
            curr = curr + i
            if curr > res:
                res = curr
            if curr < 0:
                curr = 0
        return res
