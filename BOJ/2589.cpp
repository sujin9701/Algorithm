// 230325
// BOJ 2589 보물섬
// BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 51
using namespace std;

typedef pair<int, int> pii;

queue<pii> q;
int map[MAX][MAX];
int n, m, temp, res = 0;
char a;
bool flag;
vector<pii> v;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int x, int y) {
    int dist = 0;
    int num = map[x][y];
    map[x][y]++;
    q.push(pii(x, y));
    q.push(pii(0, 0));  // depth 표시
    
    while (true) {
        if (q.empty()) break;
        pii now = q.front();
        q.pop();
        if (now.first == 0 && now.second == 0) {
            if (!q.empty()) q.push(pii(0, 0));
            dist++;
            continue;
        }

        flag = false;
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx <= 0 || nx > m || ny <= 0 || ny > n) continue;
            if (map[nx][ny] == num) {
                flag = true;
                map[nx][ny]++;
                q.push(pii(nx, ny));
            }
        }
        //q.push(pii(0, 0));
        if (!flag && num == 1) v.push_back(now);
    }

    return dist - 1;
}

int calculate(int x, int y) {
    v.clear();
    int maxDist = bfs(x, y);
    int tempDist;
    for (int i = 0; i < v.size(); i++) {
        pii now = v.at(i);
        tempDist = bfs(now.first, now.second);
        maxDist = max(maxDist, tempDist);
    }

    return maxDist;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            cin >> a;
            if (a == 'L') map[i][j] = 1;
            else map[i][j] = 0;
        }
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (map[i][j] == 1) {
                temp = calculate(i, j);
                res = max(res, temp);
            }
        }
    }

    cout << res;

    return 0;
}