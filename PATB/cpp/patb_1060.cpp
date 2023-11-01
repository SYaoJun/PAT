#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX_N = 100005;
int arr[MAX_N] = {0};

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr + 1, arr + 1 + N, [](int a, int b) { return a > b; });
    int e = 1;
    int ans = 0;
    // 找到第一个不满足骑行公里大于天数的位置终止
    // 10 8 6 4
    while (e <= N && arr[e] > e) {
        ans++;
        e++;
    }
    printf("%d\n", ans);
    return 0;
}