#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
const int MAX_N = 20050;
struct stu {
    string xue_hao;
    int program_score;  // >= 200
    int mid_score;
    int final_score;
    int total;  // >= 60
    int tag;    // 判断，有效还是无效
    stu() {
        program_score = -1;
        mid_score = -1;
        final_score = -1;
    }
} S[MAX_N];
// 排序规则：输出顺序为按照总评分数（四舍五入精确到整数）递减。若有并列，则按学号递增。
bool cmp(stu a, stu b) {
    if (a.tag != b.tag)
        return a.tag < b.tag;
    else if (a.total != b.total)
        return a.total > b.total;
    else
        return a.xue_hao < b.xue_hao;
}
int main() {
    int P, M, N;
    scanf("%d%d%d", &P, &M, &N);
    // 哈希表，已存在的学生，在数组中的下标
    map<string, int> mp;
    string str;
    int p, m, n, k = 0;
    // 1.在线编程
    for (int i = 0; i < P; i++) {
        cin >> str >> p;
        S[k].xue_hao = str;
        S[k].program_score = p;
        mp[str] = k++;
    }
    // 2. 期中成绩
    for (int i = 0; i < M; i++) {
        cin >> str >> m;
        auto it = mp.find(str);
        if (it != mp.end()) {
            S[it->second].mid_score = m;
        } else {
            // 新增同学的信息
            S[k].xue_hao = str;
            S[k].mid_score = m;
            mp[str] = k++;
        }
    }
    // 3.期末成绩
    for (int i = 0; i < N; i++) {
        cin >> str >> n;
        auto it = mp.find(str);
        if (it != mp.end()) {
            S[it->second].final_score = n;
        } else {
            S[k].xue_hao = str;
            S[k].final_score = n;
            mp[str] = k++;
        }
    }
    int valid_students = 0;
    // 针对所有的学生进行统计
    for (int i = 0; i < k; i++) {
        // 统计，总评
        if (S[i].mid_score > S[i].final_score) {
            S[i].total = (int)(S[i].mid_score * 0.4 + S[i].final_score * 0.6 + 0.5);
        } else {
            S[i].total = S[i].final_score;
        }
        // 满足条件
        if (S[i].program_score >= 200 && S[i].total >= 60) {
            S[i].tag = 1;
            valid_students++;
        } else
            S[i].tag = 2;
    }
    // 排序
    sort(S, S + k, cmp);
    for (int i = 0; i < valid_students; i++) {
        cout << S[i].xue_hao << " ";
        printf("%d %d %d %d\n", S[i].program_score, S[i].mid_score, S[i].final_score, S[i].total);
    }
    return 0;
}