# 10:48

def isSubseq(str):
    # check if hackerrank is in the string or not
    d = {}
    for s in str:
        if s not in d: d[s] = 0
        d[s] += 1
    hr = "hackerrank"
    j = 0
    while i<len(str) and j<len(hr):
        if str[i] == hr[j]:
            j += 1
        i += 1
    return j == len(str)
