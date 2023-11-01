/*
1. 统计从左往右的最大值
2. 统计从右往左的最小值
3. 遍历数组中的每个元素判断是否满足左边小，右边大
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int MAX_N = 1e5 + 5;
int arr[MAX_N], left[MAX_N], right[MAX_N];
int main() {
    memset(arr, 0, sizeof(arr));
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    left[0] = 0;
    right[n - 1] = 1e9 + 5;
    for (int i = 1; i < n; i++) {
        // 从左往右 最大值
        if (arr[i] > left[i - 1]) {
            left[i] = arr[i];
        } else {
            left[i] = left[i - 1];
        }
        // 从右往左 最小值
        if (arr[n - 1 - i] < right[n - i]) {
            right[n - 1 - i] = arr[n - 1 - i];
        } else {
            right[n - 1 - i] = right[n - i];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= left[i] && arr[i] <= right[i]) cnt++;
    }
    printf("%d\n", cnt);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= left[i] && arr[i] <= right[i]) {
            if (flag == 0) {
                printf("%d", arr[i]);
                flag = 1;
            } else {
                printf(" %d", arr[i]);
            }
        }
    }
    printf("\n");
    return 0;
}