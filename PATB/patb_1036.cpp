#include <cstdio>
int main() {
    int n;
    char ch;
    scanf("%d %c", &n, &ch);
    int t = (n + 1) / 2;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == t - 1) {
                printf("%c", ch);
            } else if (j == 0 || j == n - 1) {
                printf("%c", ch);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}