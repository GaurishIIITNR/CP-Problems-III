# हर हर महादेव
import math


t = int(input())
while t > 0 :

    n = int(input())
    s = input()
    if n > 26:
        print(-1)
        continue

    st = set()
    for i in s:
        st.add(i)
    print(n - len(st))

         

    t -= 1