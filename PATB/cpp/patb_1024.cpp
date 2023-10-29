/*
有效位是什么？
    就是一个数从左边第一个不为0的数字数起到末尾数字为止，
    所有的数字（包括0，科学计数法不计10的N次方），称为有效数字。
    0.000150
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    string src;
    getline(cin, src);
    int k = src.find('E');
    // 负数提前处理
    if (src[0] == '-') cout << "-";
    // 指数为负数
    // 1.5E-3
    // 0.0015
    if (src[k + 1] == '-') {
        int t = stoi(src.substr(k + 2));
        printf("0.");
        // 1. 输出指数为负数时添加的0的数量
        for (int i = 1; i < t; i++) {
            printf("0");
        }
        // 2. 输出有效位
        for (int j = 1; j < k; j++) {
            if (src[j] != '.') {
                printf("%c", src[j]);
            }
        }
    } else {
        // 1.5E+3
        // 1500
        int t = stoi(src.substr(k + 2));
        int cnt = 0;
        for (int j = 1; j < k; j++) {
            if (src[j] == '.') continue;
            printf("%c", src[j]);
            cnt++;
            // 小数点默认在2.458e2=245.8第一个数字之后，如果要把小数点往后移动，就相当于扩大10倍
            // 当移动的次数cnt-1恰好和t相等时，说明刚好，不能再移动了
            if (cnt - 1 == t && j != k - 1) {
                printf(".");
            }
        }
        // 因为cnt统计了第一个小数点前的数字，所以要cnt比t大才表示往右移动了t次，扩大了t次幂
        while (cnt <= t) {
            printf("0");
            cnt++;
        }
    }

    return 0;
}
