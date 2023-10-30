#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct pro {
    int f, fn, rn;  // 满分，总选项个数，正确选项个数
    char str[6];    // 正确选项内容
    int wrong, no;  // 错的人数 ,编号
};
int hash[110] = {0};
bool cmp(pro a, pro b) {
    if (a.wrong != b.wrong)
        return a.wrong > b.wrong;
    else
        return a.no < b.no;
}
int main() {
    int N, M, f, fn, rn;
    char c;
    pro temp;
    vector<pro> v;
    v.clear();
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &f, &fn, &rn);
        temp.f = f;
        temp.fn = fn;
        temp.rn = rn;
        temp.no = i + 1;
        int j;
        for (j = 0; j < rn; j++) {
            scanf(" %c", &c);
            temp.str[j] = c;
        }
        temp.str[j] = '\0';
        v.push_back(temp);
    }
    int x, single, maxw = 0;
    char s[6];
    for (int i = 0; i < N; i++) {
        single = 0;
        for (int j = 0; j < M; j++) {
            scanf(" (%d", &x);
            int k;
            for (k = 0; k < x; k++) {
                scanf(" %c", &c);
                s[k] = c;
            }
            s[k] = '\0';
            if (strcmp(v[j].str, s) == 0) {
                single += v[j].f;
            } else {
                v[j].wrong++;
                if (v[j].wrong > maxw) maxw = v[j].wrong;
            }
            scanf("%c", &c);
        }
        printf("%d\n", single);
    }
    if (maxw == 0) {
        printf("Too simple\n");
        return 0;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        if (v[i].wrong == maxw) {
            if (i == 0) printf("%d", v[i].wrong);
            printf(" %d", v[i].no);
        } else
            break;
    }
    printf("\n");
    return 0;
}