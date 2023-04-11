// 230411
// BOJ 2636 치즈
// BFS + Simulation

#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

typedef pair<int, int> pii;

queue<pii> q;
int cheese[MAX][MAX];
bool visited[MAX][MAX];
bool melt[MAX][MAX];
int n, m, melt_time, last_cnt;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool is_finished() {
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (cheese[i][j] == 1) return false;
        }
    }
    return true;
}

void init() {
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            visited[i][j] = false;
            melt[i][j] = false;
        }
    }
    return;
}

bool check_range(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}

void bfs(int x, int y) {
    visited[x][y] = true;
    q.push(pii(x, y));
    while (true) {
        if (q.empty()) break;
        pii now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (!check_range(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if (cheese[nx][ny] == 1) {
                melt[nx][ny] = true;
            }
            else if (cheese[nx][ny] == 0) {
                q.push(pii(nx, ny));
            }
        }
    }
    return;
}

void simulation() {
    // 맨 바깥 치즈 찾기
    for (int i = 0; i < n - 1; i++) {
        bfs(i, 0);
    }
    for (int j = 0; j < m - 1; j++) {
        bfs(n - 1, j);
    }
    for (int i = 1; i < n; i++) {
        bfs(i, m - 1);
    }
    for (int j = 1; j < m; j++) {
        bfs(0, j);
    }

    int cnt = 0;
    // 치즈 녹이기 + 몇 개 녹였는지 업데이트
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (melt[i][j]) {
                cheese[i][j] = 0;
                cnt++;
            }
        }
    }
    last_cnt = cnt;

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cin >> cheese[i][j];
        }
    }

    melt_time = 0;
    while (true) {
        if (is_finished()) break;

        init();
        simulation();
        melt_time++;

        // cout << "check melt cheese\n";
        // for (int j = 0; j < m; j++) {
        //     for (int i = 0; i < n; i++) {
        //         cout << melt[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        // break;
    }

    cout << melt_time << "\n" << last_cnt;

    return 0;
}