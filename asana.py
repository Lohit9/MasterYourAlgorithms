import itertools

DIRECTIONS = [(0, 1), (0, -1), (1, 0), (-1, 0)]

'''
There are 2 parts to the solution:

- find the center of the garden, where the rabbit initially is
- find the maximal path from there onwards until it reaches a square from which it can't move
'''

def carrot_count(garden):

    # makes our accesses to the garden matrix cleaner
    smart_matrix = {
        (x, y): val
        for y, row in enumerate(garden)
        for x, val in enumerate(row)
    }

    # Find the center of the matrix
    h = len(garden)
    w = len(garden[0])

    x = [w // 2]
    if w % 2 == 0:
        x.append(x[0] - 1)
    y = [h // 2]
    if h % 2 == 0:
        y.append(y[0] - 1)

    # find the square closest to the center with the highest carrot count
    center = max(
        itertools.product(x, y),
        key=lambda ij: smart_matrix[ij],
    )

    carrots = 0
    location = center

    # Move up/down/left/right based on carrot count
    while smart_matrix[location]:
         carrots += smart_matrix[location]
         smart_matrix[location] = 0

         x, y = location
         adj = [(x + px, y + py) for (px, py) in DIRECTIONS]
         location = max(adj, key=lambda xy: smart_matrix.get(xy, 0))

    # return the maximal carrots count
    return carrots




print carrot_count([[5, 7, 8, 6, 3],
             [0, 0, 7, 0, 4],
             [4, 6, 3, 4, 9],
             [3, 1, 0, 5, 8]])
