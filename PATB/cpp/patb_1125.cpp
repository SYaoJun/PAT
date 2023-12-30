#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main(){
    string s, p;
    cin >> s >>p;
    int l = 0;
    int res = 0x3f3f3f3f;
    for(int i = 0; i < s.size(); i++) {
        int k = i, j = 0;
        while(k < s.size() && j < p.size()){
            if(s[k] == p[j]) {
                k++;
                j++;
            }else {
                k++;
            }
        }
        if(j == p.size()){
            if(k-i < res){
                res = k-i;
                l = i;
            }
        }
    }
    cout<<s.substr(l, res)<<endl;
    return 0;
}