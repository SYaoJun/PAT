#include <bits/stdc++.h>
using namespace std;

int M;
struct Fraction {
    int up, down;
    float value;
} f1, f2;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int cmp(Fraction r) {
    float x, y;
    x = f1.value < f2.value ? f1.value : f2.value;
    y = f1.value > f2.value ? f1.value : f2.value;
    r.value = r.up * 1.0 / r.down;
    if (x < r.value && r.value < y)
        return 1;
    else
        return 0;
}
Fraction reduction(Fraction result) {
    if (result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

int main() {
    scanf("%d/%d %d/%d %d", &f1.up, &f1.down, &f2.up, &f2.down, &M);
    f1 = reduction(f1);
    f2 = reduction(f2);
    f1.value = f1.up * 1.0 / f1.down;
    f2.value = f2.up * 1.0 / f2.down;
    Fraction temp;
    int flag = 0;
    for (int i = 1; i < M; i++) {
        if (gcd(i, M) == 1) {
            temp.up = i;
            temp.down = M;
            if (cmp(temp) == 1) {
                if (flag == 0) {
                    printf("%d/%d", i, M);
                    flag = 1;
                } else
                    printf(" %d/%d", i, M);
            }
        }
    }
    printf("\n");
    return 0;
}