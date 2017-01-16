class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # permute()
        def p(L):
            if not L:
                return []

            res = []
            for e in L:
                perm_exc_e = p(L.difference({e}))

                if perm_exc_e:
                    inc_e = [a + [e] for a in perm_exc_e]
                else:
                    inc_e = [[e]]

                for a in inc_e:
                    res.append(a)

            return res

        return p(set(nums))

print Solution().permute([1,2,3])
