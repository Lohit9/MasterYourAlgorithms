
def printSpiral(A,m,n):
    T = 0
    B = m-1
    L = 0
    R = n-1
    dir = 0
    res = []
    while L<=R and T<=B:
        if dir == 0:
            for k in range(L,R+1):
                res.append( A[T][k] )
            T += 1
        elif dir == 1:
            for k in range(T,B+1):
                res.append( A[k][R] )
            R -= 1
        elif dir == 2:
            k = R
            while( k >= L):
                res.append( A[B][k] )
                k -= 1
            B -= 1
        elif dir == 3:
            k = B
            while( k >= T):
                res.append( A[k][L] )
                k -= 1
            L += 1
        dir = (dir+1)%4
    print res

# printSpiral(       [[ 1,  2,  3,  4,  5],
#                    [ 6,  7,  8,  9,  10],
#                    [ 11, 12, 13, 14, 15],
#                    [ 16,  17,  18,  19,  20],
#                    [ 21,  22,  23,  24,  25]], 5, 5)

printSpiral( [[5, 7, 8, 6, 3],
             [0, 0, 7, 0, 4],
             [4, 6, 3, 4, 9],
             [3, 1, 0, 5, 8]], 4, 5)
