# Asked by Uber simple question
def moveZeroe(arr):
    if arr == []: return arr
    i, j = 0,len(arr)-1
    while i<len(arr):
        if i==j: return arr
        while(arr[j] == 0):
             j -= 1
        if(arr[i] == 0):
            arr[i],arr[j] = arr[j],arr[i]
        i+=1

# Complexity:
# Time -> O(n)
# Space -> O(1)

print moveZeroe([1,2,0,3,0,1,2])
