# Standard implementation of the worls's most famous divide and conquer algorithm!
# Inversion count implementation

def merge(n1, n2, split):
    crossConflict = 0
    i,j = 0,0
    while i<len(n1) and j<len(n2):
        if n1[i] <= n2[j]:
            i += 1
        else: # n1[i] > n2[j]
            crossConflict += split - i
            j += 1
    return crossConflict

def merge_sort(nums):
    if len(nums) <= 1: return 0
    split = len(nums)/2
    leftConflict  = merge_sort(nums[:split])
    rightConflict = merge_sort(nums[split:])
    crossConflict = merge(nums[:split], nums[split:], split)
    # print leftConflict, rightConflict, crossConflict
    return leftConflict + rightConflict + crossConflict

print merge_sort([7,1,6,2,5])
print merge_sort([2,34,1,3])
print merge_sort([3,1,4,6,5,2,8,7])
print merge_sort([1, 20, 6, 4, 5])
print merge_sort([2,3,4,1])
