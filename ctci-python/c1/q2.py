# check if 2 strings are palindromes

def isPermute(s1,s2):
    if len(s1) == len(s2):
        pass
    flag = 0
    d = dict.fromkeys(s1,0)
    for c in s1:
        d[c] += 1
    for ch in s2:
        if ch in d:
            d[ch] -= 1
            if d[ch] == 0:
                flag += 1
        else: return False
    if flag == len(s1):
        return True
    return False

print isPermute("abcd", "bacd")
print isPermute("","")
print isPermute("a","b")
