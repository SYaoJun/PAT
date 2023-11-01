#include <iostream>
using namespace std;
int main() {
    int a, b;
    bool tag = false;
    while (cin >> a >> b) {
        if (b != 0) {
            if (tag == false) {
                cout << a * b << " " << b - 1;
            } else {
                cout << " " << a * b << " " << b - 1;
            }
            tag = true;
        }
    }

    if (tag == false) cout << "0 0" << endl;
    return 0;
}