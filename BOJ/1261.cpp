// 230412
// BOJ 1261 알고스팟
// Dijkstra

#include <iostream>
#include <queue>
#define MAX 101
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
bool map[MAX][MAX];
bool visited[MAX][MAX];
int wall[MAX][MAX];
int n, m;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void init() {
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            wall[i][j] = INF;
        }
    }
    return;
}

bool check_range(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    return true;
}

void move() {
    wall[1][1] = 0;
    q.push({1, 1, 0});

    while (true) {
        if (q.empty()) break;
        Data now = q.top();
        q.pop();
        if (visited[now.x][now.y]) continue;
        visited[now.x][now.y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (!check_range(nx, ny)) continue;
            // cout << "now: " << nx << ", " << ny << " -> " << wall[nx][ny] << "\n";
            if (map[nx][ny]) wall[nx][ny] = min(wall[nx][ny], now.weight + 1);
            else wall[nx][ny] = min(wall[nx][ny], now.weight);
            q.push({nx, ny, wall[nx][ny]});
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    char temp;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> temp;
            if (temp == '0') map[i][j] = false;
            else map[i][j] = true;
        }
    }

    init();
    move();
    cout << wall[n][m];

    return 0;
}