N = 200000
# 所有的素数
primes = [0] * N
is_prime = [False] * N
k = 1

def get_primes():
    global k
    for i in range(2, N):
        if not is_prime[i]:
            primes[k] = i
            # print("prime...")
            k += 1
        
        for j in range(1, k):
            if primes[j] >= N // i:
                break
            # print(primes[j])
            is_prime[i * primes[j]] = True
            if i % primes[j] == 0:
                break

if __name__ == "__main__":
    N = 200000
    m, n = map(int, input().split())
    # 求素数方法
    # 1. 欧拉筛 视频 https://www.bilibili.com/video/BV1nF411a7DF/?spm_id_from=333.999.0.0
    # 2. 埃氏筛
    # 3. 判断

    get_primes()
    cnt = 0
    for i in range(m, n+1):
        print(primes[i], end="")
        cnt += 1
        if cnt % 10 == 0:
            print()
        else:
            if i != n:
                print(" ", end="")
