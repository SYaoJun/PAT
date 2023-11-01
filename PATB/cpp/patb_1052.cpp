#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> v1, v2, v3;
string str1, str2, str3;
void init(vector<string> &v, string s) {
    int k = 0, start;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[') {
            start = i + 1;
            k = 0;
        } else if (s[i] == ']') {
            v.push_back(s.substr(start, k));
        } else {
            k++;
        }
    }
}
int main() {
    string s;
    s.clear();
    getline(cin, s);
    // 手
    init(v1, s);
    s.clear();
    getline(cin, s);
    // 眼
    init(v2, s);
    s.clear();
    getline(cin, s);
    // 口
    init(v3, s);
    int n;
    scanf("%d", &n);
    for (int u = 0; u < n; u++) {
        int arr[10] = {0};
        int flag = -1;
        for (int i = 0; i < 5; i++) {
            scanf("%d", &arr[i]);
            if (arr[i] < 1) flag = 1;
        }
        if (flag == 1) {
            cout << "Are you kidding me? @\\/@" << endl;
            continue;
        }
        int len1 = v1.size();
        int len2 = v2.size();
        int len3 = v3.size();

        if (arr[0] > len1 || arr[1] > len2 || arr[2] > len3 || arr[3] > len2 || arr[4] > len1) {
            cout << "Are you kidding me? @\\/@" << endl;
            continue;
        } else {
            // [左手]([左眼][口][右眼])[右手]
            cout << v1[arr[0] - 1] << "(" << v2[arr[1] - 1] << v3[arr[2] - 1] << v2[arr[3] - 1] << ")" << v1[arr[4] - 1]
                 << endl;
        }
    }
    return 0;
}