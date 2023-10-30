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
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &f, &fn, &rn);
        temp.f = f;
        temp.rn = rn;
        temp.no = i + 1;
        int j;
        memset(temp.arr, 0, sizeof(temp.arr));  // 数组一定要清零
        for (j = 0; j < rn; j++) {
            scanf(" %c", &c);
            temp.arr[c - 'a'] = 1;
        }
        v.push_back(temp);
    }
    int x, maxw = 0;
    float single;
    int mat[105][5];
    int arx[5];
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < N; i++) {
        single = 0;
        for (int j = 0; j < M; j++) {
            scanf(" (%d", &x);
            int k, cnt = 0;
            memset(arx, 0, sizeof(arx));
            for (k = 0; k < x; k++) {
                getchar();  // 吸收空格
                c = getchar();
                if (v[j].arr[c - 'a'] != 1) {
                    cnt += 1000;
                } else
                    cnt += 1;
                arx[c - 'a'] = 1;
            }

            if (cnt == v[j].rn) {
                single += v[j].f;
            } else if (cnt < v[j].rn && cnt > 0)
                single += v[j].f * 0.5;
            scanf("%c", &c);  // 吸收后面的括号
            for (k = 0; k < 5; k++) {
                if ((v[j].arr[k] == 1 && arx[k] != 1) || (v[j].arr[k] != 1 && arx[k] == 1)) mat[j][k]++;
            }
        }
        printf("%.1f\n", single);
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 5; j++) {
            if (mat[i][j] > maxw) maxw = mat[i][j];
        }
    }

    if (maxw == 0) {
        printf("Too simple\n");
        return 0;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 5; j++) {
            if (mat[i][j] == maxw) {
                printf("%d %d-%c\n", maxw, i + 1, j + 'a');
            }
        }
    }
    return 0;
}