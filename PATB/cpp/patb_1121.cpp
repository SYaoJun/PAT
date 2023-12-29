#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int temp2 = 0;
        bool is_ok = true;
        for(int j = 0; j < s.size(); j++){
            temp2 = temp2*10 + (s[j] - '0'); 
            if(j == 0) continue;
            if(temp2 % (j+1) != 0){
                is_ok = false;
                break;
            }
        }
        if(is_ok) puts("Yes");
        else puts("No");
    }
    return 0;
}