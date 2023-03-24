// 230324
// BOJ 1926 그림
// BFS

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 501
using namespace std;

typedef pair<int, int> pii;

int picture[MAX][MAX];
queue<pii> q;
pii now;
int n, m, temp, maxSize = 0, cnt = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int x, int y) {
    int picSize = 1;
    q.push(pii(x, y));
    while (true) {
        if (q.empty()) break;
        pii now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx < 0 || nx > m || ny < 0 || ny > n) continue;
            if (picture[nx][ny] == 1) {
                picture[nx][ny] = 0;
                picSize++;
                q.push(pii(nx, ny));
            }
        }
    }

    return picSize;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            cin >> picture[i][j];
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (picture[i][j] == 1) {
                picture[i][j] = 0;
                temp = bfs(i, j);
                maxSize = max(maxSize, temp);
                cnt++;
            }
        }
    }

    cout << cnt << "\n" << maxSize;

    return 0;
}