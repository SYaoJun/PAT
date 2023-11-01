#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAX_N = 10005;
int arr[MAX_N];
int matrix[MAX_N][1000] = {0};
int N;
bool cmp(int a, int b) { return a > b; }
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    if (N == 1) {
        printf("%d", arr[0]);
        return 0;
    }

    sort(arr, arr + N, cmp);
    // 正方形，保证边长为向上取整
    int m = (int)ceil(sqrt(1.0 * N));
    // 不能整除时，让m的值增大
    while (N % m != 0) {
        m++;
    }
    int n = N / m;
    // 行列索引下标，以及上下左右四个边界的值，now是已经填充的数量
    int i = 1, j = 1, U = 1, D = m, L = 1, R = n, now = 0;  // 1-m,1-n

    while (now < N) {
        // 向右填充
        while (now < N && j < R) {
            matrix[i][j] = arr[now++];
            j++;
        }
        // 向下填充
        while (now < N && i < D) {
            matrix[i][j] = arr[now++];
            i++;
        }
        // 向左填充
        while (now < N && j > L) {
            matrix[i][j] = arr[now++];
            j--;
        }
        // 向上填充
        while (now < N && i > U) {
            matrix[i][j] = arr[now++];
            i--;
        }
        i++, j++;
        U++, D--, R--, L++;
        // 如果中间位置未填充，需要特殊处理 比如3*3时
        if (now == N - 1) {
            matrix[i][j] = arr[now++];
        }
    }
    // 打印填充后的数组
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            printf(j == 1 ? "%d" : " %d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
