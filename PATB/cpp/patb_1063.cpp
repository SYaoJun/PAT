/*
遍历每行数据，求最大值，输出时保留两位小数点
*/
#include <cmath>
#include <cstdio>
int main() {
    int N;
    scanf("%d", &N);
    double max = -1005;
    int real, img;
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &real, &img);
        double tmp = sqrt(real * real + img * img);
        if (tmp > max) max = tmp;
    }
    printf("%.2f\n", max);
    return 0;
}