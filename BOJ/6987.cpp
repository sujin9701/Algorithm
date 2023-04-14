// 230414
// BOJ 6987 월드컵
// Backtracking

#include <iostream>
using namespace std;

int res[3][6][4];
bool possible[4];

int test[3][6];

int team1[15] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
int team2[15] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5};

void dfs(int depth) {
    // 15경기 모두 마쳤다면
    if (depth == 15) {
        // 가능한가 확인하기
        for (int k = 0; k < 4; k++) {
            // 이미 가능한거 발견했으면 패스
            if (possible[k]) continue;
            bool flag = true;
            for (int j = 0; j < 6; j++) {
                for (int i = 0; i < 3; i++) {
                    if (res[i][j][k] != test[i][j]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag) possible[k] = true;
        }
        return;
    }

    // team1 vs team2
    int t1 = team1[depth];
    int t2 = team2[depth];

    // 승패
    test[0][t1]++;
    test[2][t2]++;
    dfs(depth + 1);
    test[0][t1]--;
    test[2][t2]--;

    // 무무
    test[1][t1]++;
    test[1][t2]++;
    dfs(depth + 1);
    test[1][t1]--;
    test[1][t2]--;

    // 패승
    test[2][t1]++;
    test[0][t2]++;
    dfs(depth + 1);
    test[2][t1]--;
    test[0][t2]--;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // res[i][j][k]
    for (int k = 0; k < 4; k++) {
        for (int j = 0; j < 6; j++) {
            for (int i = 0; i < 3; i++) {
                cin >> res[i][j][k];
            }
        }
    }

    dfs(0);
    
    for (int i = 0; i < 4; i++) cout << possible[i] << " ";

    return 0;
}