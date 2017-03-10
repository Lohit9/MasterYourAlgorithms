# def fastestPath(hotels, limit):
#     if len(hotels) == 1: return 1
#     destination = hotels[0]
#     stops = [destination]
#     i = 1
#     nextD = hotels[1]
#
#     while(i+1 < len(hotels)):
#       while nextD < limit:
#           destination = hotels[i]
#           nextD = hotels[i+1]
#           i += 1
#       limit += destination
#       stops.append(destination)
#
#     # stops.append(hotels[i])
#     print stops
#     return len(stops)
#
#
# print fastestPath([0,2,7,9,13,15,16,18,25], 10)
# print fastestPath([0, 6], 6)
# print fastestPath([1,2,3], 1)
#
# # sp3 5 10 1 2 0

def merge(nums1, nums2):
      if len(nums1) == 0: return nums2
      elif len(nums2) == 0: return nums1

      i, j = 0,0
      while i<len(nums1) and j<len(nums2):
               if nums[i] < nums[j]:
                       res.append(nums1[i])
                       i +=1
               else:
                       res.append(nums2[j])
                       j += 1

      if i<len(nums1): res.append(nums1[i:])
      elif j<len(nums2): res.append(nums2[j:])
      return res
