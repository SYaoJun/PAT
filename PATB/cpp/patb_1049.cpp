/*
 { 0.1, 0.2, 0.3, 0.4 }

 C(4, 1)*0.1 = 0.4
 C(4, 2)*0.2 = 1.2
 C(4, 2)*0.3 = 1.8
 C(4, 3)*0.4 = 1.6

(0.1)
(0.1, 0.2)
(0.1, 0.2, 0.3)
(0.1, 0.2, 0.3, 0.4)
    (0.2)
    (0.2, 0.3)
    (0.2, 0.3, 0.4)
        (0.3)
        (0.3, 0.4)
            (0.4)
*/

#include <stdio.h>
#include <stdlib.h>

double x, ans = 0;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &x);
        ans += x * i * (n - i + 1);
    }
    printf("%.2f\n", ans);
    return 0;
}