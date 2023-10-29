#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_COUNT = 100005;
int N = 0, L, H;
struct E {
    int tag;
    int de, cai;
    int total;
    char no[10];
} S[MAX_COUNT];

bool cmp(E a, E b) {
    if (a.tag != b.tag) {
        return a.tag < b.tag;
    } else {
        if (a.total != b.total) {
            return a.total > b.total;
        } else if (a.de != b.de) {
            return a.de > b.de;
        } else {
            return strcmp(a.no, b.no) < 0;
        }
    }
}
int main() {
    scanf("%d %d %d", &N, &L, &H);
    int valid = 0;
    for (int i = 0; i < N; i++) {
        scanf("%s%d%d", S[valid].no, &S[valid].de, &S[valid].cai);
        S[valid].total = S[valid].de + S[valid].cai;

        if (S[valid].de < L || S[valid].cai < L) {
            // 无德无才
            continue;
        } else if (S[valid].de >= H && S[valid].cai >= H) {
            // 德才兼备
            S[valid].tag = 1;
        } else if (S[valid].de >= H && S[valid].cai >= L) {
            // 德胜才
            S[valid].tag = 2;
        } else if (S[valid].de >= L && S[valid].cai >= L && S[valid].de >= S[valid].cai) {
            // 才德兼亡 德胜才
            S[valid].tag = 3;
        } else {
            // 过线党
            S[valid].tag = 4;
        }
        valid++;
    }
    sort(S, S + valid, cmp);
    printf("%d\n", valid);
    for (int i = 0; i < valid; i++) {
        printf("%s %d %d\n", S[i].no, S[i].de, S[i].cai);
    }
    return 0;
}