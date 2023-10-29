/*
实现步骤：
1. 读入期望的字符串和实际的字符串。
2. 遍历期望的字符串，如果跟实际的字符串相同，则同时移动，否则只移动期望的字符串的下标。
3. 将不匹配的字符变成大写加入哈希表。
4. 再遍历一次期望的字符串，将存在于哈希表中的大写字符输出，并从哈希表中移除，因为只需要输出一次。
*/
#include <ctype.h>
#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;
int main() {
    char expectedInput[100], realInput[100];
    scanf("%s%s", expectedInput, realInput);
    int len1 = strlen(expectedInput);
    int len2 = strlen(realInput);
    unordered_map<char, int> mapCount;
    int i = 0, j = 0;
    while (i < len1) {
        if (expectedInput[i] == realInput[j]) {
            i++;
            j++;
        } else {
            mapCount[toupper(expectedInput[i])] = 1;
            i++;
        }
    }
    for (auto c : expectedInput) {
        if (mapCount.find(toupper(c)) != mapCount.end()) {
            printf("%c", toupper(c));
            mapCount.erase(toupper(c));
        }
    }
    printf("\n");
    return 0;
}