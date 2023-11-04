#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct stu {
    char name[10];
    int high;
};
bool cmp(stu a, stu b) {
    if (a.high != b.high)
        return a.high > b.high;
    else
        return strcmp(a.name, b.name) < 0;
}
int r, m;
vector<stu> v;
vector<vector<stu> > ans;
int idx;
void arrange_row() {
    int row_num = idx == 0 ? r + m : m;
    vector<stu> temp(row_num);
    int mid = row_num / 2;
    int step = 0;
    // 0 1 [2] 3
    // 0 1 [2] 3 4
    while (mid - step >= 0 || mid + step < row_num) {
        if (!step) {
            temp[mid + step] = v[idx++];
        } else {
            if (mid - step >= 0) {
                temp[mid - step] = v[idx++];
            }
            if (mid + step < row_num) {
                temp[mid + step] = v[idx++];
            }
        }
        step++;
    }
    ans.push_back(temp);
}
int main() {
    int n, K, h, t;
    char str[10];
    stu st;
    scanf("%d%d", &n, &K);

    for (int i = 0; i < n; i++) {
        scanf("%s%d", str, &h);
        strcpy(st.name, str);
        st.high = h;
        v.push_back(st);
    }
    // 每排m个人
    r = n % K, m = n / K;

    // 按照身高排序
    sort(v.begin(), v.end(), cmp);
    // 重新安排队形
    idx = 0;
    while (idx < n) {
        arrange_row();
    }
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf(j == 0 ? "%s" : " %s", ans[i][j].name);
        }
        printf("\n");
    }
    return 0;
}