# Given a list of integers find the highest product of 3
# integers

# nlogn
import heapq

def maxTripleProd(nums):
    nums.sort()
    res  = nums[-1]*nums[-2]*nums[-3]
    return res

print maxTripleProd([1,3,4,2,5,4])

# get max product by using a heap - O(n) but also O(n) space
def maxProductUsingHeap(nums):
    h  = None
    heapq.heapify(nums)
    print nums[-1]

    min1 = heapq.heappop(h)
    min2 = heapq.heappop(h)
    min3 = heapq.heappop(h)
    return min1*min2*min3

print maxProductUsingHeap([1,3,4,2,5,4])
