'''
(1,10) (2,6)
st1 < st2 and end1 > end 2 :
    (st1, end1)

st2 > st1 and end2 >  end1:
    (st2, end2)

(3, 5), (4, 8)
st1 < st2 and end2 > end1:
    (st1, end2)
st2 < st1 and end1 > end2:
     (st2, end1)
'''
def merge_ranges(intervals, res):
    if len(intervals) <= 1: return res.append(intervals[0])
    if len(intervals) == 2:
        st1, end1 = intervals[0][0], intervals[0][1]
        st2, end2 = intervals[1][0], intervals[1][1]
        if st1 <= st2 and end1 > end2:
            res.append((st1, end1))
            return [(st1, end1)]
        # elif st2 >= st1 and end2 > end1:
        #     print "hi"
        #     res.append((st1, end2))
        #     return [(st1, end2)]
        # elif st1 <= st2 and end2 > end1:
        #     print "hi"
        #     res.append((st1, end2))
        #     return [(st1, end2)]
        elif st2 > st1 < end2 and end2 > end1:
            res.append((st1, end2))
        elif st2 <= st1 and end1 > end2:
            res.append((st2, end1))
            return [(st2, end1)]
        # else:
            # res.append((st1, end1))
            # res.append((st2, end2))
    mid = len(intervals)//2
    leftH = merge_ranges(intervals[:mid], res)
    rightH = merge_ranges(intervals[mid:], res)
    # print leftH, rightH
    return []

result = []
# print merge_ranges([(1, 2), (2, 3)], result)
# print merge_ranges([(1, 10), (2, 6)], result)
print merge_ranges(  [(0, 1), (3, 5), (4, 8), (10, 12), (9, 10)], result)
# print merge_ranges([(0, 1), (3, 5)], result)

print result
