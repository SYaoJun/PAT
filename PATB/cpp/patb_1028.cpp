/*
1. 格式读入数据
2. 字符串比较，snprintf/sprintf的使用
3. 排序
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000005;
typedef struct Person {
    char name[8];
    int year, mon, day;
} Person;
Person E[N];
bool cmp(Person a, Person b) {
    if (a.year != b.year)
        return a.year < b.year;
    else if (a.mon != b.mon)
        return a.mon < b.mon;
    else
        return a.day < b.day;
}
int check(int year, int month, int day) {
    char birthday[16];
    snprintf(birthday, 12, "%04d%02d%02d", year, month, day);
    char oldestDay[16] = "18140906";
    char today[16] = "20140906";
    if (strcmp(birthday, oldestDay) < 0 || strcmp(birthday, today) > 0) {
        return 0;
    }
    return 1;
}
int main() {
    int n;
    scanf("%d", &n);
    char name[8];
    int year, month, day, validCount = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s %d/%d/%d", name, &year, &month, &day);
        if (check(year, month, day)) {
            strcpy(E[validCount].name, name);
            E[validCount].year = year;
            E[validCount].mon = month;
            E[validCount].day = day;
            validCount++;
        }
    }
    sort(E, E + validCount, cmp);
    if (validCount == 0) {
        printf("0\n");
    } else {
        printf("%d %s %s\n", validCount, E[0].name, E[validCount - 1].name);
    }
    return 0;
}