#include <cstdio>
#include <cstring>
const int maxn = 110;
int arr[maxn], ans[maxn] = {0};
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        memset(arr, 0, sizeof(arr));
        int count = 0, sum = 0, max = -1, min = 101;
        for (int j = 0; j < N; j++) {
            scanf("%d", arr + j);
            if (j != 0 && arr[j] >= 0 && arr[j] <= M) {
                count++;
                if (arr[j] > max) max = arr[j];
                if (arr[j] < min) min = arr[j];
                sum += arr[j];
            }
            ans[i] = (int)((arr[0] + (sum - max - min) * 1.0 / (count - 2)) / 2 + 0.5);
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}