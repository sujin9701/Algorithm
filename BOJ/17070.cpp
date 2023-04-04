// 230404
// BOJ 17070 파이프 옮기기 1
// Backtracking

#include <iostream>
#define MAX 17
using namespace std;

bool home[MAX][MAX];
int N, cnt = 0;

bool checkRange(int x, int y) {
    if (x < 1 || x > N || y < 1 || y > N) return false;
    return true;
}

bool isMovable(int x, int y) {
    if (!home[x + 1][y] && !home[x][y + 1] && !home[x + 1][y + 1]) return true;
    return false;
}

void backtracking(int x1, int y1, int x2, int y2) {
    if (x2 == N && y2 == N) {
        cnt++;
        return;
    }

    int nx, ny;
    // 가로
    if (x2 - x1 == 1 && y1 == y2) {
        nx = x2 + 1, ny = y2;
        if (checkRange(nx, ny) && !home[nx][ny]) backtracking(x2, y2, nx, ny);
        nx = x2 + 1, ny = y2 + 1;
        if (checkRange(nx, ny) && isMovable(x2, y2)) backtracking(x2, y2, nx, ny);
    }
    // 세로
    else if (x1 == x2 && y2 - y1 == 1) {
        nx = x2, ny = y2 + 1;
        if (checkRange(nx, ny) && !home[nx][ny]) backtracking(x2, y2, nx, ny);
        nx = x2 + 1, ny = y2 + 1;
        if (checkRange(nx, ny) && isMovable(x2, y2)) backtracking(x2, y2, nx, ny);
    }
    // 대각선
    else {
        nx = x2 + 1, ny = y2;
        if (checkRange(nx, ny) && !home[nx][ny]) backtracking(x2, y2, nx, ny);
        nx = x2, ny = y2 + 1;
        if (checkRange(nx, ny) && !home[nx][ny]) backtracking(x2, y2, nx, ny);
        nx = x2 + 1, ny = y2 + 1;
        if (checkRange(nx, ny) && isMovable(x2, y2)) backtracking(x2, y2, nx, ny);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            cin >> home[i][j];
        }
    }

    backtracking(1, 1, 2, 1);

    cout << cnt;

    return 0;
}