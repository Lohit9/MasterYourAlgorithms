def max_prodOfThree(nums):
    nums.sort()
    currProd, pastProd = 1, nums[-1]
    # for i in (1, len(nums)):
    #     currProd = nums[-1-i]*pastProd
    #     if pastProd > currProd:
    #         break
    #     pastProd = currProd
    return nums[-1]*nums[-2]*nums[-3]

print max_prodOfThree([1,2,3,4,-3,-7])
