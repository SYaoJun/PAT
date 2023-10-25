/*
1. 哈希计数
2. 字母大小写转换
*/
#include <ctype.h>
#include <stdio.h>
int main() {
    char hash[123] = {0}, ch;
    while ((ch = getchar()) != '\n') {
        hash[ch]++;
    }
    bool isEmptyLine = true;
    while ((ch = getchar()) != '\n') {
        // 大写，且上档键坏了
        if ((isupper(ch) && hash[43]) || hash[toupper(ch)]) {
            continue;
        } else {
            isEmptyLine = false;
            putchar(ch);
        }
    }
    if (isEmptyLine) puts("");
    return 0;
}