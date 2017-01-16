class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if prices == []: return 0
        profit, minP = 0, prices[0]
        for p in prices:
            if p < minP:
                minP = p
            profit = max(profit, p - minP)

        return profit

print Solution().maxProfit([1,1,1,1])
