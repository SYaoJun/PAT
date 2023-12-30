#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> vt(64);
    vt[0] = 0;
    vt[1] = 1;
    int t = 2;
    for(int i = 2; i < 60; i++) {
        vt[i] = vt[i-2] + vt[i-1];
        if(vt[i] >= 1e8) {
            t = i;
            break;
        }
    }
    int n;
    cin >> n;
    int min_index = 0;
    for(int i = 0; i <= t; i++){
        if(abs(n - vt[i]) < abs(n - vt[min_index])){
            min_index = i;
        }
    }

    cout<<vt[min_index]<<endl;
    return 0;
}