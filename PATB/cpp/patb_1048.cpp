#include <cstdio>
#include <cstring>
void reverse(char s[]) {  // reverse反转字符串
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        int t = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = t;
    }
}
int main() {
    char str1[110], str2[110], str[110] = {0};
    scanf("%s %s", str1, str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    reverse(str1);
    reverse(str2);
    int len = len1 > len2 ? len1 : len2;
    for (int i = 0; i < len; i++) {
        int numA = i < len1 ? str1[i] - '0' : 0;
        int numB = i < len2 ? str2[i] - '0' : 0;
        if (i % 2 == 0) {
            int tmp = (numA + numB) % 13;
            if (tmp < 10)
                str[i] = tmp + '0';
            else if (tmp == 10)
                str[i] = 'J';
            else if (tmp == 11)
                str[i] = 'Q';
            else if (tmp == 12)
                str[i] = 'K';
        } else {
            int tmp = numB - numA;
            if (tmp < 0) tmp += 10;
            str[i] = tmp + '0';
        }
    }
    reverse(str);
    puts(str);
    return 0;
}