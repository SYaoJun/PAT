/*
1. 最少是1个，即自身。
2. 枚举最小值m，统计满足条件小于等于m*p的数字数量
*/
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 100010;
int n, p, a[N];
int main() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        // 找到第一个大于m*p的位置，减去下标差值就是满足条件的元素数量
        int tmp = upper_bound(a + i + 1, a + n, (long long)a[i] * p) - a;
        ans = max(ans, tmp - i);
    }
    printf("%d\n", ans);
    return 0;
}