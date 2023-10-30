#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    for (auto &c : s) c = tolower(c);
    int sum = 0;
    for (auto &c : s) {
        if (isalpha(c)) {
            sum += c - 'a' + 1;
        }
    }
    int count_one = 0, count_zero = 0;

    while (sum) {
        if (sum & 1)
            count_one++;
        else
            count_zero++;
        sum >>= 1;
    }
    cout << count_zero << " " << count_one << endl;
    return 0;
}