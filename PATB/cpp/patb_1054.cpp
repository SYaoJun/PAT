/*
1. 字符串处理
2. 判断小数最多精确两位
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int check(char *s) {
    int len = strlen(s);
    int dot_count = 0;

    for (int i = 0; i < len; i++) {
        if (i == 0 && s[i] == '-') {
            continue;
        }
        if (s[i] == '.') {
            if (i + 2 < len - 1) {
                return 0;
            }
            dot_count++;
            continue;
        }
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return dot_count <= 1;
}
int main() {
    int N;
    scanf("%d", &N);
    char str[128];
    int count = 0;
    double sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        if (check(str) == 0) {
            printf("ERROR: %s is not a legal number\n", str);
            continue;
        }
        double num = stod(str);
        if (num < -1000 || num > 1000) {
            printf("ERROR: %s is not a legal number\n", str);
            continue;
        }
        sum += num;
        count++;
    }
    if (count == 0)
        printf("The average of 0 numbers is Undefined\n");
    else if (count == 1)
        printf("The average of 1 number is %.2f\n", sum);
    else
        printf("The average of %d numbers is %.2f\n", count, sum / count);
    return 0;
}