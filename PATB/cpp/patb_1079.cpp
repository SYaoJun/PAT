#include <cstdio>
#include <cstring>
const int MAX_N = 1010;
char str1[MAX_N], str2[MAX_N], str3[MAX_N], str[MAX_N], rev[MAX_N];
void reverse(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        // swap(s[i], s[len-1-i])
        int tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}
void copy(char a[], char b[]) {
    int len = strlen(b);
    for (int i = 0; i < len; i++) {
        a[i] = b[i];
    }
}

void add(char a[]) {
    // 高精度加法
    int c = 0, k = 0;
    int len = strlen(a);
    memset(str, 0, sizeof(str));
    for (int i = 0; i < len; i++) {
        str[k++] = (a[i] - '0' + a[len - 1 - i] - '0' + c) % 10 + '0';
        c = (a[i] - '0' + a[len - i - 1] - '0' + c) / 10;
    }
    if (c != 0) str[k] = '1';
    reverse(str);
}
int main() {
    int count = 0;
    scanf("%s", str1);
    // 大整数的加法 高精度加法
    while (count < 10) {
        copy(str2, str1);
        reverse(str1);
        add(str1);
        copy(str3, str);
        // 不用自己去实现判断回文串的函数
        if (strcmp(str1, str2) == 0) {
            printf("%s is a palindromic number.\n", str1);
            break;
        } else {
            printf("%s + %s = %s\n", str2, str1, str3);
            count++;
            copy(str1, str3);
            memset(str2, 0, sizeof(str2));
            memset(str3, 0, sizeof(str3));
        }
    }
    if (count == 10) printf("Not found in 10 iterations.\n");

    return 0;
}
