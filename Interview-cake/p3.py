def highestProdOfThree(nums):
    if nums == []: return nums
    hpTwo, hpThree, maxSoFar = [None]*len(nums), [None]*len(nums), nums[0]
    hpTwo[0], hpThree[0] = maxSoFar, maxSoFar
    #populating highest product of two so far
    for i, num in enumerate(nums):
         if i>0:
              hpTwo[i] = max(maxSoFar*num, hpTwo[i-1])
              hpThree[i] = max(hpTwo[i-1]*num, hpThree[i-1])
              if num > maxSoFar : maxSoFar = num
    return hpThree[-1]

print highestProdOfThree([-10, -10, 1,3,2])
