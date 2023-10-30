/*
将给定闭区间内的数值替换为另一个值。
*/
#include <cstdio>
const int MAX_N = 510;
int arr[MAX_N][MAX_N];
int main() {
    int M, N, A, B, C;
    scanf("%d%d%d%d%d", &M, &N, &A, &B, &C);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] >= A && arr[i][j] <= B) {
                arr[i][j] = C;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf(j == 0 ? "%03d" : " %03d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}