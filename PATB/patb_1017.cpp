#include <iostream>
#include <string>
using namespace std;
int main() {
    string a;
    int b, r = 0, temp = 0;
    cin >> a >> b;
    int len = a.length();
    // a只有一位，特殊处理
    if (len == 1) {
        cout << (a[0] - '0') / b << " " << (a[0] - '0') % b << endl;
        return 0;
    }
    for (int i = 0; i < len; i++) {
        r = (temp * 10 + a[i] - '0') / b;
        if (!(i == 0 && r == 0)) {
            cout << r;
        }
        temp = (temp * 10 + a[i] - '0') % b;
    }
    cout << " " << temp;
    return 0;
}