class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        res, i, j = [], 0, 0
        if l1 is None and l2 is None:
            return []
        elif l1 is None:
            return l2
        elif l2 is None:
            return None
        else:
          while(i < len(l1) and j < len(l2)):
            if l1[i] < l2[j]:
                res.append(l1[i])
                i += 1
            else:
                res.append(l2[j])
                j += 1

          if i<len(l1) or j<len(l2):
            if i < len(l1):
                res += l1[i:]
            elif j < len(l2):
                res += l2[j:]


        print res
        return res
# [1,4,5,6] [2,3,4,5]
Solution().mergeTwoLists([1,4,5,6], [2,3,4,5])
