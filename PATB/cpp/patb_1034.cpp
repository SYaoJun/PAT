/*
1. 输出结果没有超过整形，但是计算过程中有可能超过整形。
2. 分数要化为最简分数。
3. 负分数要加括号。
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
struct Fraction {
    ll up, down;
};
Fraction f1, f2;
// 最大公约数
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
Fraction reduction(Fraction result) {
    if (result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), abs(result.down));
        // 同时除以最大公约数
        result.up /= d;
        result.down /= d;
    }
    return result;
}
Fraction add(Fraction f1, Fraction f2) {
    // 1. a/b + d/c = (a*c + b*d)/bc
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction sub(Fraction f1, Fraction f2) {
    // 2. a/b - d/c = (a*c - b*d)/bc
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction multi(Fraction f1, Fraction f2) {
    // 3. a/b * d/c = a*d/b*c
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}
Fraction divide(Fraction f1, Fraction f2) {
    // 4. a/b / d/c 等价于 a/b * c/d = a*c/b*d
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}
void show(Fraction r) {
    r = reduction(r);
    if (r.up < 0) printf("(");
    // 如果分母为1，直接输出整数
    if (r.down == 1)
        printf("%lld", r.up);
    else {
        // 分子比分母大，先取整数部分，再取余数作为分子。
        if (abs(r.up) > r.down) {
            printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
        } else {
            printf("%lld/%lld", r.up, r.down);
        }
    }
    if (r.up < 0) printf(")");
}
int main() {
    scanf("%lld/%lld %lld/%lld", &f1.up, &f1.down, &f2.up, &f2.down);
    // 1. add
    show(f1);
    printf(" + ");
    show(f2);
    printf(" = ");
    show(add(f1, f2));
    printf("\n");
    // 2. sub
    show(f1);
    printf(" - ");
    show(f2);
    printf(" = ");
    show(sub(f1, f2));
    printf("\n");
    // 3. multi
    show(f1);
    printf(" * ");
    show(f2);
    printf(" = ");
    show(multi(f1, f2));
    printf("\n");
    // 4. divide
    show(f1);
    printf(" / ");
    show(f2);
    printf(" = ");
    // 分母为0，输出无穷
    if (f2.up == 0)
        printf("Inf");
    else
        show(divide(f1, f2));
    printf("\n");
    return 0;
}