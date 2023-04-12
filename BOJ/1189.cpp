// 230412
// BOJ 1189 컴백홈
// DFS, Brute Force, ...

#include <iostream>
#define MAX 6
using namespace std;

bool map[MAX][MAX];
bool visited[MAX][MAX];
int N, M, K, cnt = 0;
char temp;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool check_range(int x, int y) {
    if (x < 1 || x > N || y < 1 || y > M) return false;
    return true;
}

void dfs(int x, int y, int depth) {
    // cout << "arrived (" << x << ", " << y << ") -> depth: " << depth << "\n";
    if (x == N && y == 1) {
        if (depth == K) cnt++;
        // cout << "======= finish =======\n\n";
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!check_range(nx, ny)) continue;
        if (visited[nx][ny]) continue;
        if (!map[nx][ny]) continue;
        visited[nx][ny] = true;
        dfs(nx, ny, depth + 1);
        visited[nx][ny] = false;
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N >> K;
    for (int j = 1; j <= M; j++) {
        for (int i = 1; i <= N; i++) {
            cin >> temp;
            if (temp == 'T') map[i][j] = false;
            else map[i][j] = true;
        }
    }

    visited[1][M] = true;
    dfs(1, M, 1);

    cout << cnt;

    return 0;
}