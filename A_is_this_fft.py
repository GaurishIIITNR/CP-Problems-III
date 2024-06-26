MOD = 10**9 + 7


def binpowm(a, b):
    ans = 1
    while b > 0:
        if b & 1:
            ans = (ans * a)
        a = (a * a)
        b >>= 1
    return ans


def f(x):
    count = binpowm(10, x) // 3
    count %= MOD
    return count


def main():
    t = int(input())
    for _ in range(t):
        x = int(input())
        result = f(x)
        print(result)
main()
