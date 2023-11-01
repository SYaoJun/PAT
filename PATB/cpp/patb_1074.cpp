#include <cstdio>
#include <cstring>
void reverse(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        int tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}
int main() {
    char str[25], str1[25], str2[25];
    int ans[25] = {0};
    scanf("%s%s%s", str, str1, str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len = len1 > len2 ? len1 : len2;
    reverse(str1);
    reverse(str2);
    reverse(str);
    int k = 0, c = 0, A, B;
    for (int i = 0; i <= len; i++) {
        A = i < len1 ? str1[i] - '0' : 0;
        B = i < len2 ? str2[i] - '0' : 0;
        int tmp = str[i] - '0' ? str[i] - '0' : 10;
        ans[k++] = (A + B + c) % tmp;
        c = (A + B + c) / tmp;
    }
    int tag = 1;
    for (int i = k - 1; i >= 0; i--) {
        if (tag == 1 && ans[i] == 0) {
            continue;
        } else {
            printf("%d", ans[i]);
            tag = 2;
        }
    }
    if (tag == 1) printf("0");
    return 0;
}
