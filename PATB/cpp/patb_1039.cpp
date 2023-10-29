#include <cstdio>
#include <cstring>
const int N = 1005;

int main() {
    int hash[256];
    memset(hash, 0, sizeof(hash));
    char originString[N], targetString[N];
    scanf("%s%s", originString, targetString);
    int len1 = strlen(originString);
    int len2 = strlen(targetString);
    for (int i = 0; i < len1; i++) {
        hash[originString[i]]++;
    }
    // 2 -2 8
    for (int i = 0; i < len2; i++) {
        hash[targetString[i]]--;
    }
    int countPositive = 0, countNegative = 0;
    for (int i = 0; i < 256; i++) {
        if (hash[i] > 0)
            countPositive += hash[i];
        else if (hash[i] < 0)
            countNegative += (-hash[i]);
    }
    if (countNegative > 0)
        printf("No %d\n", countNegative);
    else
        printf("Yes %d\n", countPositive);
    return 0;
}
