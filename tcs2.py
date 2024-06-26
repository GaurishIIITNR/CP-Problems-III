def cnv(s):
    n = len(s)
    print(s)
    if s == "Start" or s == "End":
        return -1
    if s[0] == 'S' or s[0] == 'L':
        n = len(s)
        tmp = s[2:n - 1]
        print(tmp)
        if tmp == "Start":
            return 1
        if tmp == "End":
            return 100
        return int(tmp)
    return -1


def HHM():
    adj = [[] for _ in range(101)]
    st = 100
    i = 0
    ss = []
    while i < 10:
        lst = list(input().split())
        ss.append(lst)
        i += 1
    print(s)

    ii, jj = 0, 0
    while st > 0:
        for i in range(10):
            s = ss[ii][jj]
            print(s)
            if cnv(s) > 0:
                adj[st].append(cnv(s))
            st -= 1
            jj += 1

        ii += 1
        st -= 9
        for i in range(10):
            s = ss[ii][jj]
            print(s)
            if cnv(s) > 0:
                adj[st].append(cnv(s))
            st += 1
            jj += 1
        ii += 1
        st -= 11

    # v = list(map(int, input.split()))
    # src = 0
    # sn = 0
    # ld = 0

    # for x in v:
    #     src += x
    #     while len(adj[src]) > 0:
    #         if src > adj[src][0]:
    #             sn += 1
    #         else:
    #             ld += 1
    #         src = adj[src][0]

    #     if src == 100:
    #         print("Possible", sn, ld)
    #         return

    # if src == 0 or src == 1:
    #     print("Not possible", sn, ld, "Start" if src == 0 else "End")
    # else:
    #     print("Not possible", sn, ld, src)


if __name__ == "__main__":
    t = 1
    # t = int(input())
    while t:
        HHM()
        t -= 1
