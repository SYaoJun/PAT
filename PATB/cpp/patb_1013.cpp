#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX_N = 1e6 + 7;
const int num = 1e4 + 3;
int k = 1;
int p[MAX_N], prime[num];
void allPrime() {
    for (int i = 2; i < MAX_N; i++) {
        if (!p[i]) {
            prime[k++] = i;
            if (k > 10001) return;
            for (int j = i + i; j < MAX_N; j += i) p[j] = 1;
        }
    }
}

int main() {
    allPrime();
    int cnt = 0;
    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        cnt++;
        cout << prime[i];
        if (cnt % 10 == 0 || cnt == n - m + 1)
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}
