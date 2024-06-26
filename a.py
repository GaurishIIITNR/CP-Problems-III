def opr(n):
    s = str(n)
    r = ""

    for i in range(len(s)):
        if i % 2 == 0:
            r += s[i]

    return int(r)


n = int(raw_input())

a = map(int, raw_input().split())
mp = {}

for x in a:
    if x - opr(x) in mp:
        mp[x - opr(x)] += 1
    else:
        mp[x - opr(x)] = 1

ans = 0
for x in mp:
    ans += mp[x] * (mp[x] - 1) / 2

print ans