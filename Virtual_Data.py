# हर हर महादेव
import math


# t = int(input())
t = 1
while t > 0 :

    n = int(input())
    a = input()
    b = input()
    lst = []
    cnt = 0
    for i in range(n):
        if a[i] != b[i]:
            cnt += 1
        else:
            if cnt > 0: 
                lst.append(cnt)
            cnt = 0
    if cnt > 0:
        lst.append(cnt)
    # print(lst)
    if len(lst) == 0:
        print(n*(n-1))
    elif len(lst) == 1:
        print(2*( n - 1))
    elif len(lst) > 2:
        print(0)
    else :
        print(6)
    t -= 1