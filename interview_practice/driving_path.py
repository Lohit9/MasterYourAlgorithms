def fastestPath(hotels, limit):
    if len(hotels) == 1: return 1
    destination = hotels[0]
    stops = [destination]
    i = 1
    nextD = hotels[1]

    while(i+1 < len(hotels)):
      while nextD < limit:
          destination = hotels[i]
          nextD = hotels[i+1]
          i += 1
      limit += destination
      stops.append(destination)

    # stops.append(hotels[i])
    print stops
    return len(stops)


print fastestPath([0,2,7,9,13,15,16,18,25], 10)
print fastestPath([0, 6], 6)
print fastestPath([1,2,3], 1)
