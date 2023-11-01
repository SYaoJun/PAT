/*
1. 处理不在有效分数区间的评分，忽略掉。
2. 最大值和最小值
3. 四舍五入
*/
#include <cstdio>
#include <cstring>
const int MAX_N = 110;
int arr[MAX_N];
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        memset(arr, 0, sizeof(arr));
        int count = 0, sum = 0, max = -1, min = 100001;
        for (int j = 0; j < N; j++) {
            scanf("%d", arr + j);
            if (j != 0 && arr[j] >= 0 && arr[j] <= M) {
                count++;
                if (arr[j] > max) max = arr[j];
                if (arr[j] < min) min = arr[j];
                sum += arr[j];
            }
        }
        // 直接输出
        int ans = (int)((arr[0] + (sum - max - min) * 1.0 / (count - 2)) / 2 + 0.5);
        printf("%d\n", ans);
    }
    return 0;
}