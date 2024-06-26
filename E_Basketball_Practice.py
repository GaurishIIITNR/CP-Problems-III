t = int(input())
while t > 0:
    n = int(input())
    lst = list(map(int, input().split()))
    odd, even = 0, 0 
    for i in lst :
         if i & 1 :
            odd += 1
         else :
            even += 1
    if odd == 0 or even == 0:
        print("YES")
    else :
        print("NO")
    t -= 1