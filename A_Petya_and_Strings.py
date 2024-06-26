def solve():
    a = input().lower()
    b = input().lower()
    for i in range(len(a)):
        if(a[i] < b[i]):
            print(-1)
            return 
        elif(a[i] > b[i]):
            print(1)
            return 
    print(0)
solve()