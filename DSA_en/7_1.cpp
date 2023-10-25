/*
1. 求最大和，是连续的。// n*n // 动态规划: 当前这个数值，a. 接在前面结果的后面 b. 独立作为起始元素
2. 最大和的起始位置和终止位置。
3. 最大和为负数，特殊处理，最大和置为0，输出整个序列的第一个元素和最后一个元素。
4. 保证起始和终止的编号最小。
*/
#include <stdio.h>
#define MAX 100000

int main() {
    int K, i, arr[MAX];
    int maxSum, tempSum, maxL, maxR, tempL, tempR;
    scanf("%d", &K);
    for (i = 0; i < K; i++) {
        scanf("%d", &arr[i]);
    }
    maxSum = -1; /* 子列和非负即可更新子列和的最大值及最大和子列的左右边界 */
    tempSum = 0;
    tempL = 0; /* 序列长度至少为1，初始段至少含arr[0] */
    tempR = 0;
    maxL = -1;
    maxR = -1;
    for (i = 0; i < K; i++) {
        tempSum += arr[i];
        tempR = i;              /* 固定当前左边界，当前右边界随i增加 */
        if (tempSum > maxSum) { /* 小于或等于则不更新，以得最小的边界*/
            maxSum = tempSum;
            maxL = tempL;
            maxR = tempR;
        }
        if (tempSum < 0) { /* 开始下一段固定左边界的检测 */
            tempSum = 0;
            tempL = i + 1; /* 丢弃和为负的此段 */
            tempR = i + 1;
        }
    }
    if (maxSum < 0) {
        printf("0 %d %d", arr[0], arr[K - 1]);
    } else {
        printf("%d %d %d", maxSum, arr[maxL], arr[maxR]);
    }

    return 0;
}
