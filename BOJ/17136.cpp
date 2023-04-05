// 230404
// BOJ 17136 색종이 붙이기
// Backtracking

#include <iostream>
#include <algorithm>
#define MAX 10
#define INF 987654321
using namespace std;

bool paper[MAX][MAX];
int cntBySize[6] = {0, };
int minCnt = INF;

bool isPossible(int x, int y, int size) {
    for (int j = y; j < y + size; j++) {
        for (int i = x; i < x + size; i++) {
            if (!paper[i][j]) return false;
        }
    }
    return true;
}

void update(int x, int y, int s, bool status) {
    for (int j = y; j < y + s; j++) {
        for (int i = x; i < x + s; i++) {
            paper[i][j] = status;
        }
    }

    return;
}

void backtracking(int x, int y, int cnt) {
    int nx, ny;
    bool flag = false;
    // 덮어야 하는 위치 찾기
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            if (paper[i][j]) {
                flag = true;
                nx = i, ny = j;
                break;
            }
        }
        if (flag) break;
    }
    // 덮어야 할 곳 없는 경우
    if (!flag) {
        minCnt = min(minCnt, cnt);
        return;
    }

    // 가지치기
    if (minCnt < cnt) return;

    // 색종이 붙이기 시도
    for (int s = 5; s > 0; s--) {
        if (nx + s > MAX || ny + s > MAX || cntBySize[s] == 5) continue;
        if (isPossible(nx, ny, s)) {
            // 붙이고
            update(nx, ny, s, 0);
            cntBySize[s]++;
            // 백트래킹
            backtracking(nx, ny, cnt + 1);
            // 없애고
            update(nx, ny, s, 1);
            cntBySize[s]--;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int totalCnt = 0;
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            cin >> paper[i][j];
            if (paper[i][j]) totalCnt++;
        }
    }

    if (totalCnt == MAX * MAX) {
        cout << 4;
        return 0;
    }

    backtracking(0, 0, 0);

    if (minCnt == INF) cout << -1;
    else cout << minCnt;

    return 0;
}