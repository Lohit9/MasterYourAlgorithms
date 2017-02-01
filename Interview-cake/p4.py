def merge_ranges(intervals):
    d = {}
    startTimes = []
    for l in intervals:
        d[l[0]] = l[1]
        startTimes.append(l[0])
    # Assuming no duplicates and no 2 tuples have the same start time, this case
    # can be handled easily by preprocessing the intervals list
    startTimes.sort()
    currEndTime, nextEndTime = d[startTimes[0]], d[startTimes[0]]
    '''
    idea:
    currStartTime - prevEndTime <= 0 --> [prevStartTime, currEndTime]
    currStartTime - prevEndTime > 0 --> leave intervals as they are [prevStartTime, endTime], [currStartTime, endtime]
    '''
    currStartTime, prevStartTime = None, startTimes[0]
    currEndTime, prevEndTime = None, d[startTimes[0]]
    res = []
    s,e = None, None
    for i in range(1, len(startTimes)):
        currStartTime, currEndTime = startTimes[i], d[startTimes[i]]
        if currStartTime - prevEndTime <= 0:
            s = min(prevStartTime, currStartTime)
            e = max(prevEndTime, currEndTime)
            if (prevStartTime,e) not in res:
                res.append((prevStartTime,e))
            d[prevStartTime], d[currStartTime] = None, None
            prevStartTime, prevEndTime = prevStartTime, e
        else:
            prevStartTime, prevEndTime = currStartTime, currEndTime

    for st in startTimes:
        if d[st] != None:
            res.append((st, d[st]))
    return res



print merge_ranges([(1, 2), (2, 3)])
print merge_ranges([(0, 1), (3, 5), (4, 8), (10, 12), (9, 10)])
print merge_ranges([(1, 5), (2, 3)])
print merge_ranges([(1, 10), (2, 6), (3, 5), (7, 9)])
print merge_ranges([(1, 10), (2, 6)])
  # [(0, 1), (3, 5), (4, 8), (10, 12), (9, 10)]
