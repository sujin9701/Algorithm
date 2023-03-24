// 230322
// BOJ 7576 토마토
// BFS

#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

typedef pair<int, int> pii;

int tomato[MAX][MAX];
queue<pii> q;
pii temp;

int M, N, cnt = 0;
bool flag = true;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= M; i++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) q.push(pii(i, j));
            else if (tomato[i][j] == 0) flag = false;
        }
    }
    q.push(pii(0, 0));

    if (!flag) {
        while (true) {
            if (q.empty()) break;
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == 0 && y == 0 && !q.empty()) {
                q.push(pii(0, 0));
                cnt++;
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx * ny == 0 || nx > M || ny > N) continue;  // out of range
                if (tomato[nx][ny] == 0) {
                    tomato[nx][ny] = 1;
                    q.push(pii(nx, ny));
                }
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (tomato[i][j] == 0) {
                cnt = -1;
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}