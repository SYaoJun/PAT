#include <cstdio>
int main() {
    int n;
    char x, y, p;
    char str[110] = {0}, s[10];
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%s", s);
            if (s[2] == 'T') str[i] = s[0] - 'A' + '1';
        }
    }
    puts(str);
    return 0;
}