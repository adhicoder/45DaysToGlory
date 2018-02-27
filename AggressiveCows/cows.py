import math

def minDistance(x, C):
    d = []
    for i in range(0, len(x)-1):
        d.append(x[i+1]-x[i])
        i = i+1

    l = min(d)
    h = sum(d)

    while l < h:
        allowedNo=1
        x = math.floor((h+l)/2)
        distance = 0
        for i in range(len(d)):
            if distance + d[i] <= x:
                distance = distance + d[i]
            else:
                allowedNo = allowedNo + 1
                distance = 0
            i = i+1
    
        if allowedNo >= C:
            l = x + 1
        else:
            h = x
    return l


x = []
numbers = []
t = int(input())
for i in range(t):
    NC = input()
    N, C = NC.split(" ")
    N = int(N)
    C = int(C)
    for j in range(N):
        x.append(int(input()))
    x.sort()
    numbers.append(minDistance(x, C))
for j in numbers:
    print(j)

