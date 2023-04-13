// 230413
// BOJ 2665 미로만들기
// BFS + Dijkstra

#include <iostream>
#include <queue>
#define MAX 51
#define INF 987654321
using namespace std;

struct Data {
    int x, y, weight;
    Data(int x, int y, int weight): x(x), y(y), weight(weight) {};
    bool operator < (const Data d) const {
        return weight > d.weight;
    }
};

priority_queue<Data> q;
char room[MAX][MAX];
bool visited[MAX][MAX];
int n, min_cnt = INF;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool check_range(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n) return false;
    return true;
}

void bfs() {
    visited[1][1] = true;
    q.push({1, 1, 0});

    while (true) {
        if (q.empty()) break;
        Data now = q.top();
        q.pop();
        if (now.x == n && now.y == n) {
            min_cnt = min(min_cnt, now.weight);
        }
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (!check_range(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if (room[nx][ny] == '0') q.push({nx, ny, now.weight + 1});
            else q.push({nx, ny, now.weight});
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> room[i][j];
        }
    }

    bfs();
    cout << min_cnt;

    return 0;
}