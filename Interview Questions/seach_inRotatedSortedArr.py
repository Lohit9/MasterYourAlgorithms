class Solution(object):
    def findPivot(self, nums):
        start, end = 0, len(nums)-1
        while start < end:
            if nums[start] > nums[start + 1]:
                return start+1
            start += 1

    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        pivotIndex = self.findPivot(nums)
        # print pivotIndex
        first, last = 0, len(nums)-1
        start, end = -1, -1
        if nums[pivotIndex] == target: return pivotIndex
        elif nums[first] <= target < nums[pivotIndex]:
            start, end = first, pivotIndex
        elif nums[pivotIndex] < target <= nums[last]:
            start, end = pivotIndex, last
        return self.binSearch(nums, target, start, end)

    def binSearch(self, nums, target, start, end):
        # print nums, start, end
        if nums == []: return -1
        first, last = start, end
        while first <= last:
            mid = (first + last)//2
            # print mid
            if nums[mid] == target:
                # print "hi"
                return mid
            elif nums[mid] > target:
                last = mid - 1
            elif nums[mid] < target:
                first = mid + 1
        return -1




print Solution().search([4,5,6,7,0,1,2], 3)




'''
Possible cases for inserting an element into a
sorted linked list:

- if the node is None, just insert the Node and nextisNone
-keep traversing the linkedlist until we have
and keep track of next and prev at each step
and then if  prev < val < next  then thats the location
to insert the Node
- prev.next = newNode
- newNode.next = next

'''
