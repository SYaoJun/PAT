#include <bits/stdc++.h>
int main() {
    int N, D, T, p = 0, v = 0;
    float e;
    scanf("%d %f %d", &N, &e, &D);
    for (int i = 0; i < N; i++) {
        scanf("%d", &T);
        int cnt = 0;
        float x;
        for (int j = 0; j < T; j++) {
            scanf("%f", &x);
            if (x < e) cnt++;
        }
        if (cnt > T / 2) {
            if (T > D)
                v++;
            else
                p++;
        }
    }
    printf("%.1f%% %.1f%\n", p * 100.0 / N, v * 100.0 / N);
    return 0;
}