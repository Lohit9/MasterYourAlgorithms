# # check whether input string is a permutation of a palindrome

# bf
# def isPalindrome(s):
#     s.strip(" ")
#     l = len(s)-1
#     n = (len(s) - 1) // 2
#     if (n < 2):
#         return True
#     for i in range(n):
#         if s[i].lower() != s[l-i].lower():
#             print s[i].lower(), s[l-i].lower()
#             return False
#     return True
#
#

import re

def isPalindrome(s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.replace(".",'')
        s = re.sub('[^0-9a-zA-Z]+', '*', s)
        s = s.lower()
        l = len(s)
        d = dict.fromkeys(s,0)
        oddVals = 0
        evenVals = 0
        if l < 2 : return True
        for ch in s:
            d[ch] += 1

        for value in d.values():
           if value % 2 != 0:
              oddVals = True
           elif value % 2 == 0:
              evenVals += 1
        if (evenVals % 2 != 0) and (oddVals % 2 != 0 or oddVals == 0): return True

        return False


print isPalindrome("Tact Coa")
print isPalindrome("")
print isPalindrome(" ")
print isPalindrome("Tact Ca")
print isPalindrome("A man, a plan, a canal: Panama")
print isPalindrome("race a car")
print isPalindrome("rr")
print isPalindrome("0P")
print isPalindrome("0.")
print isPalindrome("a.")
print isPalindrome("abb")
