#include <cstring>
#include <iostream>
using namespace std;
// 欧拉筛法
const int N = 1e5 + 5;
bool st[N];  // false表示是素数
int primes[N];
int k;
void getPrimes() {
    for (int i = 2; i < N; i++) {
        if (!st[i]) primes[k++] = i;  // 2, 3, 5, 7
        // 核心： 每个合数都是被最小的素数筛掉的
        for (int j = 0; primes[j] * i < N; j++) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
int main() {
    int n;
    cin >> n;
    memset(st, 0, sizeof st);
    getPrimes();
    int cnt = 0;
    for (int i = 1; primes[i] <= n; i++) {
        if (primes[i] - primes[i - 1] == 2) cnt++;
    }
    cout << cnt << endl;
    return 0;
}