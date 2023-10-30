/*
1. 排序【省略】 按照名次的参赛者
2. 计算质数

注意点：
1. ID输出需要保证是4位数字
2. 检查ID是否在参赛选手中
3. ID是否检查过
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
const int N = 1e5 + 5;
int hash_map[N];
bool is_prime(int x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    for (int i = 3; i < x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    memset(hash_map, -1, sizeof(hash_map));
    int n, id;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &id);
        hash_map[id] = i;
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &id);
        printf("%04d: ", id);
        if (hash_map[id] == -1) {
            puts("Are you kidding?");
        } else if (hash_map[id] == 0) {
            puts("Checked");
        } else if (hash_map[id] == 1) {
            puts("Mystery Award");
            hash_map[id] = 0;
        } else if (is_prime(hash_map[id])) {
            puts("Minion");
            hash_map[id] = 0;
        } else {
            puts("Chocolate");
            hash_map[id] = 0;
        }
    }
    return 0;
}
