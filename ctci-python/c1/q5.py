def edit_away(s1,s2):
    d = dict.fromkeys(list(s1))
    if s1==s2: return True
    else:
        lenDiff = len(s1) - len(s2)
        count = 0
        if (lenDiff in [-1,0,1]):
            for each in s2:
                if each in d:
                    count +=1
            if (lenDiff == -1 and count == len(s1)) or (lenDiff in [0,1] and count == len(s1)-1):
                return True

    return False

print edit_away("pale", "ple")
print edit_away("pales", "pale")
print edit_away("pales", "pale")
print edit_away("pale", "bake")
