#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAX_N = 1e5 + 5;
struct node {
    int add, data, next;
} Node[MAX_N];
int main() {
    int st, n, k, a;
    // 分成3类，主动用数组将数据分割开
    vector<int> v[3];
    scanf("%d%d%d", &st, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        Node[a].add = a;
        scanf("%d%d", &Node[a].data, &Node[a].next);
    }
    int p = st;
    while (p != -1) {
        if (Node[p].data < 0) {
            v[0].push_back(p);
        } else if (Node[p].data <= k && Node[p].data >= 0) {
            v[1].push_back(p);
        } else {
            v[2].push_back(p);
        }
        p = Node[p].next;
    }
    int flag = 0;
    // 依次输出3个类别的数据
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (flag == 0) {
                printf("%05d %d", v[i][j], Node[v[i][j]].data);
                flag = 1;
            } else {
                printf(" %05d\n%05d %d", v[i][j], v[i][j], Node[v[i][j]].data);
            }
        }
    }
    printf(" -1\n");
    return 0;
}