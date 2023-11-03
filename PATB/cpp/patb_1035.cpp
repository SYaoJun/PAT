/*
1. 实现插入排序和归并排序
2. 两种算法的中间的结果，是否相等。
*/
#include <algorithm>
#include <cstdio>
using namespace std;
int origin[105], target[105], temp[105];
int n;

int check() {
    for (int i = 0; i < n; i++) {
        if (origin[i] != target[i]) return 0;
    }
    return 1;
}

int check2() {
    for (int i = 0; i < n; i++) {
        if (temp[i] != target[i]) return 0;
    }
    return 1;
}
int InsertSort() {
    int j = 0, flag = 0;
    // 8 7 2 10
    // 2 7 8
    for (int i = 1; i < n; i++) {
        // 把当前这个key插入到前面已经排好序的部分
        int key = origin[i];
        j = i - 1;
        while (j >= 0 && origin[j] > key) {
            // 后移当前位置的j到j+1
            origin[j + 1] = origin[j];
            // j往前移动
            j--;
        }
        origin[j + 1] = key;
        if (flag) return 1;
        if (check()) {
            flag = 1;
        }
    }
    return 0;
}
void MergeSort() {
    int flag = 0;
    // 步长是8，总数也是8，可以再进行一次归并
    for (int step = 2; step / 2 <= n; step = step * 2) {
        for (int i = 0; i < n; i += step) {
            // 将给定步长范围内的数排序
            sort(temp + i, temp + min(step + i, n));
        }

        if (flag) return;
        if (check2()) {
            flag = 1;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", origin + i);
        temp[i] = origin[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", target + i);
    }

    int t = InsertSort();
    if (t) {
        printf("Insertion Sort\n");
        for (int i = 0; i < n; i++) {
            printf(i == 0 ? "%d" : " %d", origin[i]);
        }
        return 0;
    }
    MergeSort();
    printf("Merge Sort\n");
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : " %d", temp[i]);
    }

    return 0;
}