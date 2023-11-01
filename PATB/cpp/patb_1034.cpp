#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
struct Fraction {
    ll up, down;
};
Fraction f1, f2;
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
        result.up /= d;
        result.down /= d;
    }
    return result;
}
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction sub(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction multi(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}
Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}
void show(Fraction r) {
    r = reduction(r);
    if (r.up < 0) printf("(");
    if (r.down == 1)
        printf("%lld", r.up);
    else {
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
    show(f1);
    printf(" + ");
    show(f2);
    printf(" = ");
    show(add(f1, f2));
    printf("\n");
    show(f1);
    printf(" - ");
    show(f2);
    printf(" = ");
    show(sub(f1, f2));
    printf("\n");
    show(f1);
    printf(" * ");
    show(f2);
    printf(" = ");
    show(multi(f1, f2));
    printf("\n");
    show(f1);
    printf(" / ");
    show(f2);
    printf(" = ");
    if (f2.up == 0)
        printf("Inf");
    else
        show(divide(f1, f2));
    printf("\n");
    return 0;
}