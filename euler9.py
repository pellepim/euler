comps = 0
for c in range(334,500):
    for a in range(1, (1000-c)/2):
        b = (1000 - c) - a
        comps += 1
        if a**2 + b**2 == c**2:
            print "a,b,c =",a,b,c
            print comps
