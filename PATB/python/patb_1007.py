def prime_table(n):
    prime = [0] * (n + 1)
    p = [0] * (n + 1)
    k = 0
    for i in range(2, n+1):
        if p[i] == 0:
            prime[k] = i
            j = i
            while j <= n:
                p[j] = 1
                j += i
            k += 1
    return prime[:k]

def main():
    n = int(input())
    ans = 0
    if n <= 2:
        print("0")
        return
    if n == 3:
        print("1")
        return
    prime = prime_table(n)
    for i in range(len(prime) - 1):
        if prime[i + 1] - prime[i] == 2:
            ans += 1
            i += 1
    print(ans)

if __name__ == "__main__":
    main()