// 230324
// BOJ 1012 유기농 배추
// BFS

#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

typedef pair<int, int> pii;

bool field[MAX][MAX];
queue<pii> q;
int T, M, N, K, x, y, cnt;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void init() {
    cnt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            field[i][j] = false;
        }
    }

    return;
}

void bfs(int x, int y) {
    q.push(pii(x, y));
    pii now;
    while (true) {
        if (q.empty()) break;
        now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx < 0 || nx > 50 || ny < 0 || ny > 50) continue;
            if (field[nx][ny]) {
                field[nx][ny] = false;
                q.push(pii(nx, ny));
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> M >> N >> K;

        init();
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            field[x][y] = true;
        }

        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                if (field[i][j]) {
                    cnt++;
                    field[i][j] = false;
                    bfs(i, j);
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}