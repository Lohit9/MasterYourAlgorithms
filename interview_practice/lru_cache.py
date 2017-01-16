class LRUCache(object):
    maxSize, currentSize, usageDict, cacheDict, lastKey, lasVal = 0, 0, {}, {}, None, None
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.maxSize = capacity

    def get(self, key):
        """
        :rtype: int
        """
        if key not in self.cacheDict: return -1
        if key not in self.usageDict:
            self.usageDict[key] = 1
        else:
            self.usageDict[key] += 1
        return self.cacheDict[key]


    def set(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: nothing
        """
        if self.maxSize == 0: return -1
        elif self.currentSize >= self.maxSize and key not in self.cacheDict:
            minKey, minVal = self.lastKey, self.lastVal
            for k,v in self.cacheDict.items():
                if v < minVal:
                    minVal = v
                    minKey = k

            # self.cacheDict.pop(minKey, None)
            del self.cacheDict[minKey]
            self.cacheDict[key] = value

        else:
            if key not in self.cacheDict:
               self.cacheDict[key] = value
               self.currentSize += 1


            # if key not in self.usageDict:
            #     self.usageDict[key] = 1
            # else:
            #     self.usageDict[key] += 1

            self.lastKey = key
            self.lastVal = value

# 1,[set(2,1),get(2),set(3,2),get(2),get(3)]

lru = LRUCache(1)
lru.set(2,1)
print lru.get(2)
lru.set(3,2)
print lru.get(2)
print lru.get(3)
