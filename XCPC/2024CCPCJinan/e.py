T = int(input())
while T:
    T -= 1
    A, B, C, X, Y, D = map(int, input().split())
    if D <= X:
        print(A)
        continue
    ans = (D + X - 1) // X * A
    if D % X <= Y:
        ans = min(ans, D // X * A + B * (D % X))
    else:
        ans = min(ans, D // X * A + B * Y + C * (D % X - Y))
        if D // X * Y >= D % X:
            ans = min(ans, D // X * A + B * (D % X))
    if D <= X + Y:
        ans = min(ans, A + B * (D - X))
    if D >= X + Y:
        ans = min(ans, A + B * Y + C * (D - X - Y))
        ans = min(ans, D // (X + Y) * (A + B * Y) + C * (D % (X + Y)))
        lft = D % (X + Y)
        if lft >= X:
            ans = min(ans, D // (X + Y) * (A + B * Y) + A + B * (lft - X))
        elif D // (X + Y) * Y >= X - lft:
            ans = min(ans, D // (X + Y) * (A + B * Y) + A - B * (X - lft))
        else:
            ans = min(ans, D // (X + Y) * (A + B * Y) + A)
    print(ans)