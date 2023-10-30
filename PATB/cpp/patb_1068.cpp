/*
1. 哈希表重复值判断
计算与周围8个邻居的差值，但是要超过给定阈值。
如果有多个和没有需要特殊处理。
*/

#include <cstdio>
#include <map>
using namespace std;
int arr[1005][1005];
int x, y, T;
map<int, int> mp;
int M, N;
int abs(int x) { return x < 0 ? -x : x; }

int check(int i, int j) {
    if (mp[arr[i][j]] != 1) return 0;
    for (int u = -1; u <= 1; u++) {
        for (int v = -1; v <= 1; v++) {
            if (u == 0 && v == 0) continue;
            if (i + u < 1 || i + u > N || j + v < 1 || j + v > M) continue;
            if (abs(arr[i][j] - arr[i + u][j + v]) <= T) return 0;
        }
    }
    x = i, y = j;
    return 1;
}
int main() {
    mp.clear();
    scanf("%d%d%d", &M, &N, &T);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &arr[i][j]);
            mp[arr[i][j]]++;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (check(i, j)) {
                cnt++;
            }
        }
    }
    if (cnt == 0)
        printf("Not Exist\n");
    else if (cnt > 1)
        printf("Not Unique\n");
    else
        printf("(%d, %d): %d\n", y, x, arr[x][y]);
    return 0;
}