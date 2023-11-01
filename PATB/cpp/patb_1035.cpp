// 暴力搜索
// 枚举两种算法的中间的结果，挨个比对。
#include <algorithm>
#include <cstdio>
using namespace std;
int arr[105], brr[105], tmp[105];
int n;

int check() {
    for (int i = 0; i < n; i++) {
        if (arr[i] != brr[i]) return 0;
    }
    return 1;
}

int check2() {
    for (int i = 0; i < n; i++) {
        if (tmp[i] != brr[i]) return 0;
    }
    return 1;
}
int InsertSort() {
    int j = 0, flag = 0;
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        if (flag == 1) return 1;
        if (check()) {
            flag = 1;
        }
    }
    return 0;
}
void MergeSort() {
    int flag = 0;
    for (int step = 2; step / 2 <= n; step = step * 2) {
        for (int i = 0; i < n; i += step) {
            sort(tmp + i, tmp + min(step + i, n));
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
        scanf("%d", arr + i);
        tmp[i] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", brr + i);
    }

    int t = InsertSort();
    if (t) {
        printf("Insertion Sort\n");
        for (int i = 0; i < n; i++) {
            printf(i == 0 ? "%d" : " %d", arr[i]);
        }
        return 0;
    }
    MergeSort();
    printf("Merge Sort\n");
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : " %d", tmp[i]);
    }

    return 0;
}