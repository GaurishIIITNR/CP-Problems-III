t = int(input())

while t > 0:

    n = int(input())

    one, two = 0, 0

    turn = 1

    while n > 0:

        if turn % 2:
            one += 1
            n -= 1

        elif turn % 2 == 0 and n > 1:
            two += 1
            n -= 2

        else:
            one += 1
            n -= 1
        turn += 1
        
    if one - two == 0:

        for i in range(one):
            print("21", end='')
        print()

    elif one - two == 1:
        print("1", end = '')

        for i in range(two):
            print("21", end='')
        print()

    else :

        one -= 2
        two += 1
        
        print("2", end = '')
        for i in range(one):
            print("12", end='')
        print()
        
    t -= 1
