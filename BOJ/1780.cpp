// 230412
// BOJ 1780 종이의 개수
// Divide and Conquer

#include <iostream>
#define MAX 2200
using namespace std;

int paper[MAX][MAX];
// bool visited[MAX][MAX];
int paper_cnt[3];  // 0: -1, 1: 0, 2: 1  -> +1 인덱스에 저장하면 됨
int n;

void backtracking(int start_x, int start_y, int cur_len) {
    int first_num = paper[start_x][start_y];
    // bool flag = true;

    for (int j = start_y; j < start_y + cur_len; j++) {
        for (int i = start_x; i < start_x + cur_len; i++) {
            // if (visited[i][j]) continue;
            if (paper[i][j] != first_num) {
                // flag = false;
                int new_len = cur_len / 3;
                backtracking(start_x, start_y, new_len);
                backtracking(start_x + new_len, start_y, new_len);
                backtracking(start_x + new_len * 2, start_y, new_len);

                backtracking(start_x, start_y + new_len, new_len);
                backtracking(start_x + new_len, start_y + new_len, new_len);
                backtracking(start_x + new_len * 2, start_y + new_len, new_len);

                backtracking(start_x, start_y + new_len * 2, new_len);
                backtracking(start_x + new_len, start_y + new_len * 2, new_len);
                backtracking(start_x + new_len * 2, start_y + new_len * 2, new_len);

                return;
            }
        }
    }

    // if (flag) {
    //     for (int j = start_y; j < start_y + cur_len; j++) {
    //         for (int i = start_x; i < start_x + cur_len; i++) {
    //             visited[i][j] = true;
    //         }
    //     }
    //     paper_cnt[first_num + 1]++;
    // }

    paper_cnt[first_num + 1]++;

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> paper[i][j];
        }
    }
    
    backtracking(1, 1, n);

    for (int i = 0; i < 3; i++) {
        cout << paper_cnt[i] << "\n";
    }

    return 0;
}