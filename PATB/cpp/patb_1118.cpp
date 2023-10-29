#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int    n = 11;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s.find("+") != string::npos) {
            int u = 0;
            while (s[ u ] != '+') {
                u++;
            }
            int a = stoi(s.substr(0, u));
            int b = stoi(s.substr(u + 1));
            printf("%d", a + b);
        } else if (s.find("-") != string::npos) {
            int u = 0;
            while (s[ u ] != '-') {
                u++;
            }
            int a = stoi(s.substr(0, u));
            int b = stoi(s.substr(u + 1));
            printf("%d", a - b);
        } else if (s.find("*") != string::npos) {
            int u = 0;
            while (s[ u ] != '*') {
                u++;
            }
            int a = stoi(s.substr(0, u));
            int b = stoi(s.substr(u + 1));
            printf("%d", a * b);
        } else if (s.find("/") != string::npos) {
            int u = 0;
            while (s[ u ] != '/') {
                u++;
            }
            int a = stoi(s.substr(0, u));
            int b = stoi(s.substr(u + 1));
            if (a == 0) {
                printf("0");

            } else
                printf("%d", a / b);
        } else if (s.find("^") != string::npos) {
            int u = 0;
            while (s[ u ] != '^') {
                u++;
            }
            int a = stoi(s.substr(0, u));
            int b = stoi(s.substr(u + 1));
            printf("%d", int(pow(a, b)));
        } else if (s.find("%") != string::npos) {
            int u = 0;
            while (s[ u ] != '%') {
                u++;
            }
            int a = stoi(s.substr(0, u));
            int b = stoi(s.substr(u + 1));
            printf("%d", a % b);
        } else if (s == "ling") {
            printf("0");
        } else if (s == "yi") {
            printf("1");
        } else if (s == "er") {
            printf("2");
        } else if (s == "san") {
            printf("3");
        } else if (s == "si") {
            printf("4");
        } else if (s == "wu") {
            printf("5");
        } else if (s == "liu") {
            printf("6");
        } else if (s == "qi") {
            printf("7");
        } else if (s == "ba") {
            printf("8");
        } else if (s == "jiu") {
            printf("9");
        } else if (s.size() > 4 && s.substr(0, 4) == "sqrt") {
            int a = stoi(s.substr(4));
            printf("%d", int(sqrt(a)));
        } else {
            printf("%d", stoi(s));
        }
    }
    printf("\n");
}