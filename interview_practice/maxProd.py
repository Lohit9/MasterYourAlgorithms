# For example, given the array [2,3,-2,4],
# the contiguous subarray [2,3] has the largest product = 6.

class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: return None
        currProd, futureProd, ultMaxProd = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            futureProd = currProd * nums[i]
            # print currProd, futureProd
            if futureProd > currProd:
                currProd *= nums[i]
            else:
                ultMaxProd = max(ultMaxProd, currProd)
        ultMaxProd = max(ultMaxProd, currProd)
        return ultMaxProd

print Solution().maxProduct([1,2,3,4,5])
print Solution().maxProduct([-1,-2,-3])
