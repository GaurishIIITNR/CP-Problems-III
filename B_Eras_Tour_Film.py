lst = list(map(int, input().split()))

req = lst[2] *(lst[2] + 1) // 2
req *= lst[0]

if req > lst[1]:
    print(req - lst[1])
else:
    print(0)
