def display_result(arr):
    nf, nm = map(int, arr[0].split())
    appetite = list(map(int, arr[1].split()))
    happiness = list(map(int, arr[2].split()))
    total_appetite = sum(appetite)
    total_happiness = sum(happiness)
    
    zipped = list(zip(appetite, happiness))
    zipped.sort(key=lambda x: x[1])
    
    def max_invited_friends(pivot_start, pivot_end, max_friends):
        pivot = (pivot_start + pivot_end) // 2
        min_val = sum([(a + (pivot - 1) * b) for a, b in zipped[:pivot]])
        
        if min_val <= nm:
            if pivot < pivot_end:
                return max_invited_friends(pivot + 1, pivot_end, pivot)
            else:
                return pivot
        else:
            if pivot > pivot_start:
                return max_invited_friends(pivot_start, pivot - 1, max_friends)
            else:
                return max_friends
    
    print(max_invited_friends(1, nf, 0))

if __name__ == "__main__":
    input_lines = [line.strip() for line in input().splitlines()]
    display_result(input_lines)


