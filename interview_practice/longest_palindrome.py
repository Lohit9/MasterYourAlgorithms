class Solution(object):
    # Bruteforce
    def bfLongestPalin(self, s):
        curr = ""
        for i in range(len(s)):
            curr = s[i]
            for j in range(len(s[i:])):
                curr += s[j]
                print s[i] + s[j]
        return s

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        longestBF = self.bfLongestPalin(s)
        return longestBF

# print Solution().longestPalindrome("babad")
print Solution().longestPalindrome("cbbd")
# print Solution().longestPalindrome("q")
