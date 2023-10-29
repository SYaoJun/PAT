//
// Created by 姚军 on 2022/11/26.
//

/*
 * 总结：
 * 1. 知识点：模拟，数学
 * 2. 浮点数和格式
 *
 * */
#include <iostream>

using  namespace std;
void print(int a, bool is_last) {
    if(a == -1) cout<<"N";
    else cout<<a;
    if (!is_last) cout<<" ";
}
int main() {
    int n;
    cin >> n;
    int a1 = -1, a2 = -1, a3 = -1, a5 = -1;
    double a4 = -1;
    int cnt = 0;
    int x;
    bool is_positive = true;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if (x % 5 == 0) {
            if(x % 2 == 0) {
                if(a1 == -1) a1 = x;
                else {
                    a1 += x;
                }
            }
        }
        if (x % 5 == 1) {
            if(is_positive) {
                if (a2 == -1) a2 = x;
                else a2 += x;
            }else a2 -= x;
            is_positive = !is_positive;
        }
        if (x % 5 == 2) {
            if(a3 == -1) a3 = 1;
            else a3 ++;
        }
        // 3 8 18 = 29/3 = 9.666
        if (x % 5 == 3) {
            if(cnt == 0) {
                a4 = x;
            } else {
              a4 += x;
            }
            cnt++;
        }
        if (x % 5 == 4) {
            if (a5 == -1)  a5 = x;
            else {
                a5 = max(a5, x);
            }
        }
    }

    print(a1, false);
    print(a2, false);
    print(a3, false);
    if (cnt == 0) {
        cout<<"N ";
    }else{
        printf("%.1f ", a4/cnt);
    }
    print(a5, true);
    return 0;
}
