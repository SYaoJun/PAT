//
// Created by 姚军 on 2022/11/26.
//
/**
 * 1. 预先处理素数
 * 2. 查表，注意打印格式
 * pat特色：行末不能有多余空格
 * */

#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5;
// 所有的素数
int primes[N];
bool is_prime[N];
int k = 1;
void get_primes() {
    // 欧拉筛，O(n)
    for (int i = 2; i < N; i++) {
        if (!is_prime[i]) primes[k++] = i;
        // 核心：每一个合数，只被最小的质因子筛掉
        for (int j = 0; primes[j] < N/i; j++) {
            is_prime[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
int main() {
    memset(is_prime, 0, sizeof(is_prime));
    memset(primes, 0, sizeof(primes));
    int m, n;
    // 求素数方法
    // 1. 欧拉筛 视频 https://www.bilibili.com/video/BV1nF411a7DF/?spm_id_from=333.999.0.0
    // 2. 埃氏筛
    // 3. 判断

    get_primes();
    cin >> m >> n;
    // 1e6范围内，有多少个素数
    int cnt = 0;
    for (int i = m; i <= n; i++) {
        cout<<primes[i];
        cnt++;
        if(cnt % 10 == 0) {
            cout<<endl;
        }else{
            if(i != n) cout<<" ";
        }
    }
    return 0;
}