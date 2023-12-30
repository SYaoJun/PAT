#include <iostream>
#include <string>
using namespace std;
int n, d;
string s;
double x;

void do_print(double x){
    int k = 0, u = 0;
    bool dot = false;
    s = to_string(x);
    while(k <= d){
        putchar(s[u]);
        if(s[u] == '.') dot = true;
        if(dot) k++; 
        u++;
    }
}
void do_plus(double x){
    double t = 1;
    for(int j = 0; j < d; j++) {
        t /= 10.0;
    }
    x += t;
    do_print(x);
}
void do_case_one(){
    // 3.1415
    // 0.001
    int k = 0;
    int u = 0;
    int dot_index = 0;
     while(u < s.size()){
        if(s[u] == '.') {
            dot_index = u;
            break;
        }
        u++;
    }
    if(s[dot_index+d+1] >= '5'){
        do_plus(x);
    }else{
        do_print(x);
    }
}
int main(){
    cin >> n >> d;
    int op;
    for(int i = 0; i < n; i++) {
        cin >> op >> x;
        s = to_string(x);
        if(op == 1){
            do_case_one();
        }else if(op == 2){
             do_print(x);
        }else{
            int k = 0;
            int u = 0;
            bool dot = false;
            int dot_index;
            while(u < s.size()){
                if(s[u] == '.') {
                    dot = true;
                    dot_index = u;
                    break;
                }
                u++;
            }
            if(dot_index+d +1 >= s.size()){
                puts("xxx");
            }else{
                if(s[dot_index+d+1] <='4') {
                    do_print(x);
                }else if(s[dot_index+d+1] >= '6') {
                    do_plus(x);
                }else{
                    bool count_non_zero = false;
                    for(int v = dot_index+d+2; v < s.size(); v++){
                        if(s[v] != '0') {
                            count_non_zero = true;
                            break;
                        }
                    }
                    
                    if(count_non_zero || (s[dot_index+d]-'0')%2==1){
                        do_plus(x);
                    }else{
                        do_print(x);
                    }
                }
            }
        }
        printf("\n");
    }


    return 0;
}
/*
3 3.14251   3.143   // 3 非0
3 3.14250   3.142   // 最后有效位为2 不进位
3 3.14150   3.142   // 最后有效位为1 进位
3 3.14140   3.141   // 4舍
3 3.14160   3.142   // 6入
*/