

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long arr[ 1010 ];
long long get_sum(long long c) {
    if (c == 0)
        return 0;
    long long sum = -1;
    while (c) {
        long long temp = c % 10;
        if (sum == -1)
            sum = temp * temp * temp;
        else
            sum *= temp * temp * temp;
        c /= 10;
    }
    long long sum2 = 0;
    while (sum) {
        sum2 += sum % 10;
        sum /= 10;
    }
    return sum2;
}

int main() {
    int  n1, n2;
    bool isAllOneDigit = true;
    int  arr2[ 10 ];
    memset(arr2, 0, sizeof(arr2));
    cin >> n1 >> n2;
    memset(arr, 0, sizeof(arr));
    int j = 0;
    for (int i = n1; i <= n2; i++) {
        arr[ j++ ] = i;
    }

    // return 0;
    while (true) {
        isAllOneDigit = true;
        for (int u = 0; u < j; u++) {
            if (arr[ u ] >= 10) {
                isAllOneDigit = false;
                break;
            }
        }
        if (isAllOneDigit) {
            break;
        }
        for (int u = 0; u < j; u++) {
            arr[ u ] = get_sum(arr[ u ]);
        }
    }
    int maxCount = 0;
    for (int u = 0; u < j; u++) {
        arr2[ arr[ u ] ]++;
        maxCount = max(maxCount, arr2[ arr[ u ] ]);
    }
    cout << maxCount << endl;
    bool isFirst = true;
    for (int u = 0; u < 10; u++) {
        if (arr2[ u ] == maxCount) {
            if (isFirst) {
                isFirst = false;
                cout << u;
            } else {
                cout << " " << u;
            }
        }
    }
    cout << endl;

    return 0;
}
