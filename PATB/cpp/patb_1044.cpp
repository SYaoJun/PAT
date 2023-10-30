/*
1. 字符串处理
2. 进制转换
火星文的特征：不管低位还是高位，英文字母都是3位，可以根据字符串的长度进行区分。
读入一整行字符串，可以用fgets来替代gets，直接使用gets会有安全性问题，存在字符串溢出风险。
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
char mar_units[][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char mar[][5] = {"x", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
char str[110];

void mar2earth() {
    int len = strlen(str);
    if (len == 3) {
        for (int i = 1; i <= 13; i++) {
            if (strcmp(str, mar[i]) == 0) {
                printf("%d\n", i * 13);
                return;
            }
        }
        for (int i = 0; i < 13; i++) {
            if (strcmp(str, mar_units[i]) == 0) {
                printf("%d\n", i);
                return;
            }
        }
    } else {
        char first[16];
        char second[16];
        strncpy(first, str, 3);
        first[3] = '\0';
        strncpy(second, str + 4, 3);
        second[3] = '\0';
        int sum = 0;
        for (int i = 1; i < 13; i++) {
            if (strcmp(first, mar[i]) == 0) {
                sum = i * 13;
                break;
            }
        }
        for (int i = 0; i < 13; i++) {
            if (strcmp(second, mar_units[i]) == 0) {
                sum += i;
                break;
            }
        }
        printf("%d\n", sum);
    }
}
void earth2mar() {
    int i, sum = 0;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        sum = sum * 10 + str[i] - '0';
    }

    if (sum < 13) {
        printf("%s\n", mar_units[sum]);
    } else {
        int g = sum % 13;
        int s = sum / 13 % 13;
        if (g != 0)
            printf("%s %s\n", mar[s], mar_units[g]);
        else
            printf("%s\n", mar[s]);
    }
}
int main() {
    int N, i;
    scanf("%d", &N);
    getchar();
    for (i = 0; i < N; i++) {
        fgets(str, sizeof(str), stdin);
        int length = strlen(str);
        str[length - 1] = '\0';
        if (isdigit(str[0])) {
            earth2mar();
        } else {
            mar2earth();
        }
    }
    return 0;
}