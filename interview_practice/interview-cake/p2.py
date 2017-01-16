# Finding the product of each array element but self

# Finding the product of each array element but self

class Solution(object):
    def computeProductArr(self, nums):
        # nums = [1]
        output = [1]
        currProd = 1
        for i in range(1,len(nums)):
            currProd *= nums[i - 1]
            output.append(currProd)
        return output

    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if nums == []: return []
        left, right, res = [],[],[]

        leftProd = self.computeProductArr(nums)
        rightProd = self.computeProductArr(nums[::-1])
        rightProd = rightProd[::-1]
        print leftProd, rightProd

        for i in range(len(leftProd)):
            leftProd[i] = leftProd[i]*rightProd[i]

        return leftProd

print Solution().productExceptSelf([1, 7, 3, 4])
