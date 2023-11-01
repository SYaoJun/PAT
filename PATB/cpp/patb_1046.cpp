/*
1. 同赢和同输跳过
2. 统计甲乙输掉的次数
*/

#include <cstdio>
int main() {
    int N, a, ap, b, bp;
    scanf("%d", &N);
    int aCount = 0, bCount = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d%d", &a, &ap, &b, &bp);
        if (ap == a + b && bp != ap)
            bCount++;
        else if (bp == a + b && ap != bp)
            aCount++;
    }
    printf("%d %d\n", aCount, bCount);
    return 0;
}