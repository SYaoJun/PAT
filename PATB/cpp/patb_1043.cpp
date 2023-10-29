// 1. 字符串
// 2. 统计

#include <cstring>
#include <iostream>
#include <string>
using namespace std;
bool isEnd;
int bucket[6];
void print_char(int i) {
    if (bucket[i] != 0) {
        switch (i) {
            case 0:
                cout << 'P';
                break;
            case 1:
                cout << 'A';
                break;
            case 2:
                cout << 'T';
                break;
            case 3:
                cout << 'e';
                break;
            case 4:
                cout << 's';
                break;
            case 5:
                cout << 't';
                break;
        }
        isEnd = false;
        bucket[i]--;
    }
}
int main() {
    string s;
    cin >> s;

    memset(bucket, 0, sizeof(bucket));
    for (auto c : s) {
        if (c == 'P') bucket[0]++;
        if (c == 'A') bucket[1]++;
        if (c == 'T') bucket[2]++;
        if (c == 'e') bucket[3]++;
        if (c == 's') bucket[4]++;
        if (c == 't') bucket[5]++;
    }

    while (true) {
        isEnd = true;
        for (int i = 0; i < 6; i++) {
            print_char(i);
        }
        if (isEnd) {
            break;
        }
    }
    cout << endl;
    return 0;
}