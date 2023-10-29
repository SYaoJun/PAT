#include <stdio.h>
#include <cstring>
char str[100005];
int p[100005] = {0};
int t[100005] = {0};
int main() {
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        // 因为要操作相邻元素，所谓边界情况特殊处理
        if (i == 0) {
            if (str[i] == 'P') p[i] = 1;
            if (str[len - 1 - i] == 'T') t[len - 1 - i] = 1;
            continue;
        }
        // P字符从左往右遍历
        if (str[i] == 'P') {
            p[i] = p[i - 1] + 1;
        } else {
            p[i] = p[i - 1];
        }
        // T字符从右往左遍历
        if (str[len - i - 1] == 'T') {
            t[len - i - 1] = t[len - i] + 1;
        } else {
            t[len - i - 1] = t[len - i];
        }
    }
    long long ans = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == 'A') {
            ans = (ans + p[i] * (long long)t[i]) % 1000000007;
        }
    }
    printf("%lld\n", ans);
    return 0;
}