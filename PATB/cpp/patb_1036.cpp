#include <cstdio>
int main() {
    int columns;
    char ch;
    scanf("%d %c", &columns, &ch);
    // 四舍五入，因为为小数时，总是x.5，四舍五入后就是向上取整，
    // 我们直接在做除法时就向上取整。
    int rows = (columns + 1) / 2;  // a/b 向上取整  (a+b-1)/b
    // 打印二维字符，其中有空格
    // 特殊处理：1. 第一行和最后一行 2. 第一列和最后一列
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0 || i == rows - 1) {
                printf("%c", ch);
            } else if (j == 0 || j == columns - 1) {
                printf("%c", ch);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}