#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct pro {
    int f, rn;   // 满分，总选项个数，正确选项个数
    int arr[6];  // 正确选项内容 转换为整型方便哈希
    int no;
};

int main() {
    int N, M, f, fn, rn;
    char c;
    pro temp;
    vector<pro> v;
    v.clear();
    scanf("%d%d", &N, &M);
    // M道题的信息
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &f, &fn, &rn);
        temp.f = f;
        temp.rn = rn;
        temp.no = i + 1;
        int j;
        memset(temp.arr, 0, sizeof(temp.arr));  // 数组一定要清零
        for (j = 0; j < rn; j++) {
            scanf(" %c", &c);
            // 表示这个选项存在
            temp.arr[c - 'a'] = 1;
        }
        v.push_back(temp);
    }
    int x, max_wrong = 0;
    float single;
    int mat[105][5];
    int arx[5];
    memset(mat, 0, sizeof(mat));
    // N个学生
    for (int i = 0; i < N; i++) {
        single = 0;
        // M道题
        for (int j = 0; j < M; j++) {
            scanf(" (%d", &x);
            int k, cnt = 0;
            memset(arx, 0, sizeof(arx));
            // 当前这道题的选择情况
            for (k = 0; k < x; k++) {
                getchar();  // 吸收空格
                c = getchar();
                // 这个选项不是正确答案
                if (v[j].arr[c - 'a'] != 1) {
                    cnt += 1000;
                } else {
                    cnt += 1;
                }
                arx[c - 'a'] = 1;
            }
            // 学生选择的数量跟这道题正确答案的数量相等，则得满分
            if (cnt == v[j].rn) {
                single += v[j].f;
            } else if (cnt < v[j].rn && cnt > 0)
                single += v[j].f * 0.5;
            scanf("%c", &c);  // 吸收后面的括号
            // 遍历每个选项，统计选错的信息
            for (k = 0; k < 5; k++) {
                if ((v[j].arr[k] == 1 && arx[k] != 1) || (v[j].arr[k] != 1 && arx[k] == 1)) {
                    mat[j][k]++;
                }
            }
        }
        printf("%.1f\n", single);
    }
    // 统计错得最多的次数
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 5; j++) {
            if (mat[i][j] > max_wrong) max_wrong = mat[i][j];
        }
    }

    if (max_wrong == 0) {
        printf("Too simple\n");
        return 0;
    }
    // 从小到大判断
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 5; j++) {
            if (mat[i][j] == max_wrong) {
                printf("%d %d-%c\n", max_wrong, i + 1, j + 'a');
            }
        }
    }
    return 0;
}