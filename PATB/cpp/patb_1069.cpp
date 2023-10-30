/*
按照间隔处理中奖的人，注意用哈希表去重。
*/
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
    int M, N, S;
    vector<string> v;
    map<string, int> mp;
    mp.clear();
    v.clear();
    string s;
    char str[25];
    scanf("%d%d%d", &M, &N, &S);
    for (int i = 0; i < M; i++) {
        scanf("%s", str);
        s = str;
        v.push_back(s);
        mp[v[i]] = 0;
    }
    vector<string>::iterator it;
    int i = S - 1;
    int flag = 0;
    while (i < M) {
        if (mp[v[i]] != 1) {
            printf("%s\n", v[i].c_str());
            mp[v[i]] = 1;
            i = i + N;
            flag = 1;
        } else {
            i = i + 1;
        }
    }
    if (flag == 0) printf("Keep going...\n");
    return 0;
}