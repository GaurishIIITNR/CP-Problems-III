t = int(input())

for _ in range(t):

    a, b = 0, 0

    for i in range(3):

        x, y = map(int, input().split())

        a += x

        b += y
 
    k = int(input())

    ans = float('inf')
 
    for i in range(-k, k + 1):

        x = (a * a) + (b + i) * (b + i)

        y = (a + i) * (a + i) + (b * b)

        ans = min(ans, min(x, y))
 
    print(ans)