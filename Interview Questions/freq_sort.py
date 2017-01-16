def frequencySort(s):
    d = {}
    res = ""

    d = {x:s.count(x) for x in s}

    # print d
    rngDict = {v : k for k, v in d.items()}
    # print rngDict

    x = [each+1 for each in range(len(s))]
    x.reverse()
    for i in x:
        if i in rngDict:
            if type(rngDict[i]) == list:
              for k in range(i):
                for each in rngDict[i]:
                    res += each
                    # print each
            else:
                 for k in range(i):
                    res += rngDict[i]
    return res

print frequencySort("cccaaa")
