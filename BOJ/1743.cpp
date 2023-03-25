// 230325
// BOJ 1743 음식물 피하기
// BFS

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;

typedef pair<int, int> pii;

queue<pii> q;
bool way[MAX][MAX];
int n, m, k, x, y, temp, maxSize = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void init() {
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            way[i][j] = false;
        }
    }

    return;
}

int bfs(int x, int y) {
    int food = 1;
    while (true) {
        if (q.empty()) break;
        pii now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx <= 0 || nx > m || ny <= 0 || ny > n) continue;
            if (way[nx][ny]) {
                food++;
                way[nx][ny] = false;
                q.push(pii(nx, ny));
            }
        }
    }

    return food;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    init();

    for (int i = 0; i < k; i++) {
        cin >> y >> x;
        way[x][y] = true;
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (way[i][j]) {
                way[i][j] = false;
                q.push(pii(i, j));
                temp = bfs(i, j);
                maxSize = max(maxSize, temp);
            }
        }
    }

    cout << maxSize;

    return 0;
}