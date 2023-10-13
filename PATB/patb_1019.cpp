#include <cstdio>
#include <map>
using namespace std;
int check(char a, char b) {
    if (a == b)
        return 0;
    else if (a == 'J' && b == 'B')
        return 1;
    else if (a == 'B' && b == 'C')
        return 1;
    else if (a == 'C' && b == 'J')
        return 1;
    else
        return -1;
}
int main() {
    int n;
    char ch1, ch2;
    map<char, int> mpA, mpB;
    mpA.clear();
    mpB.clear();
    int win = 0, even = 0, lose = 0;
    int arrA[110] = {0};
    int arrB[110] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c %c", &ch1, &ch2);
        if (check(ch1, ch2) == 1) {
            win++;
            mpA[ch1]++;
        } else if (check(ch1, ch2) == 0) {
            even++;
        } else {
            lose++;
            mpB[ch2]++;
        }
    }
    printf("%d %d %d\n", win, even, lose);
    printf("%d %d %d\n", lose, even, win);
    map<char, int>::iterator it;
    int max = 0;
    for (it = mpA.begin(); it != mpA.end(); it++) {
        if (it->second > max) {
            ch1 = it->first;
            max = it->second;
        }
    }
    max = 0;
    for (it = mpB.begin(); it != mpB.end(); it++) {
        if (it->second > max) {
            ch2 = it->first;
            max = it->second;
        }
    }
    printf("%c %c\n", ch1, ch2);
    return 0;
}