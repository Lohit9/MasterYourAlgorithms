def incrementNum(nums):
    numStr = ""
    for num in nums:
        numStr.append(str(num))
    return list(str(int(numStr) + 1 ))
