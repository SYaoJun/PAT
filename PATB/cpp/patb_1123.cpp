/*
1. 字符串
2. 模拟
注意点
1. 分类讨论正负号
2. 给浮点数补齐末尾0到有效位截止
3. 避免输出-0.000这样错误的字符串 0.000
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
using namespace std;
int n, d;
string s;

string prepare_(string str, bool &exist_non_zero) {
    string ret = "";
    int i = 0;
    int n = str.size();
    // 保留小数点前的数字
    for (; i < n; i++) {
        if (str[i] == '.') break;
        ret += str[i];
    }
    // 如果此时为字符串结尾，表示当前数字字符串中没有小数点，我们人为加小数点
    if (i == n) {
        str += '.';
    }
    // 后面加很多0，防止后续操作越界
    for (int j = 0; j < 205; j++) {
        str += '0';
    }
    // 新的字符串长度
    n = str.size();
    // 到有效位数时的索引
    int last_valid_position = i + 1 + d;
    for (; i < last_valid_position; i++) {
        ret += str[i];
    }
    ret += str[i];
    // 判断第一个无效位后面的字符中是否有非0的数
    for (int j = i + 1; j < n; j++) {
        if (str[j] != '0') {
            exist_non_zero = true;
            break;
        }
    }
    return ret;
}

void plus_one() {
    int c = 1;
    for (int j = s.size() - 1; j >= 0; j--) {
        if (s[j] == '.' || s[j] == '-') continue;
        int val = s[j] - '0' + c;
        s[j] = val % 10 + '0';
        c = val / 10;
    }
    if (c == 1) {
        if (s[0] == '-') {
            s = s.substr(1);
            s = "-1" + s;
        } else
            s = "1" + s;
    }
    cout << s;
}
void print_() {
    // 截断一个负数时可能会导致产生-0.0000这类输出，但是正确的输出应该是0.0000，不需要前面的负号
    if (s[0] == '-') {
        bool is_all_zero = true;
        int n = s.size();
        for (int j = 1; j < n; j++) {
            if (isdigit(s[j]) && s[j] != '0') {
                is_all_zero = false;
            }
        }
        if (is_all_zero) {
            s = s.substr(1);
        }
    }
    cout << s;
}
int main() {
    cin >> n >> d;
    int op;
    for (int i = 0; i < n; i++) {
        cin >> op >> s;
        bool exist_non_zero = false;
        s = prepare_(s, exist_non_zero);
        char first_invalid = s.back();
        s.pop_back();
        if (op == 1) {
            if (first_invalid > '4') {
                plus_one();
            } else {
                print_();
            }
        } else if (op == 2) {
            print_();
        } else {
            if (first_invalid >= '6') {
                plus_one();
            } else if (first_invalid <= '4') {
                print_();
            } else {
                if (exist_non_zero || (s.back() - '0') % 2 == 1) {
                    plus_one();
                } else {
                    print_();
                }
            }
        }
        printf("\n");
    }

    return 0;
}
/*
3 3.14251   3.143   // 3 非0
3 3.14250   3.142   // 最后有效位为2 不进位
3 3.14150   3.142   // 最后有效位为1 进位
3 3.14140   3.141   // 4舍
3 3.14160   3.142   // 6入
*/