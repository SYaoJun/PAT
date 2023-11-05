def print_result(a, is_last):
    if a == -1:
        print("N", end="")
    else:
        print(a, end="")
    if not is_last:
        print(" ", end="")

def main():
    arr = [int(i) for i in input().split()]
    n = arr[0]
    a1, a2, a3, a4, a5 = -1, -1, -1, -1, -1
    cnt = 0
    is_positive = True
    idx = 1
    for _ in range(n):
        x = arr[idx]
        idx+=1
        if x % 5 == 0:
            if x % 2 == 0:
                if a1 == -1:
                    a1 = x
                else:
                    a1 += x
        if x % 5 == 1:
            if is_positive:
                if a2 == -1:
                    a2 = x
                else:
                    a2 += x
            else:
                a2 -= x
            is_positive = not is_positive
        if x % 5 == 2:
            if a3 == -1:
                a3 = 1
            else:
                a3 += 1
        if x % 5 == 3:
            if cnt == 0:
                a4 = x
            else:
                a4 += x
            cnt += 1
        if x % 5 == 4:
            if a5 == -1:
                a5 = x
            else:
                a5 = max(a5, x)

    print_result(a1, False)
    print_result(a2, False)
    print_result(a3, False)
    if cnt == 0:
        print("N", end=" ")
    else:
        print(f"{a4 / cnt:.1f}", end=" ")
    print_result(a5, True)

if __name__ == "__main__":
    main()
