n = int(input())
lst = list(map(int, input().split()))
st = set()
for i in lst:
    if i > 0:
        st.add(i)
print(len(st))