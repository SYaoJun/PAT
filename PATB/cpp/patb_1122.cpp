#include <iostream>
using namespace std;
int main(){
    int sum = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x%2 == 1) sum ^= x;
    }
    cout<<sum<<endl;
    return 0;
}