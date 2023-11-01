#include <algorithm>
#include <cmath>
#include <cstdio>
int main() {
    int N, D, K, p = 0, v = 0;
    float e;
    // 读入N套房，低电量阈值，观察期天数
    scanf("%d %f %d", &N, &e, &D);
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        // 观测数据总量
        int cnt = 0;
        float x;
        for (int j = 0; j < K; j++) {
            scanf("%f", &x);
            if (x < e) cnt++;
        }
        if (cnt > K / 2) {
            if (K > D)
                v++;
            else
                p++;
        }
    }
    printf("%.1f%% %.1f%%\n", p * 100.0 / N, v * 100.0 / N);
    return 0;
}