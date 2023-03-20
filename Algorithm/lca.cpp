// 230318
// LCA 기본 코드
// BOJ 11437 LCA

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#define MAX 50001
#define MAXH 17
using namespace std;

typedef pair<int, int> pii;

vector<int> v[MAX];
queue<pii> q;
int DP[MAX][MAXH];
int depth[MAX];
int n, h, m, a, b;

void init() {
    h = 0;
    for (int i = 0; i <= n; i++) {
        v[i].clear();
        depth[i] = 0;
    }

    return;
}

// dfs로 모든 node의 depth와 tree의 depth 구하기
void dfs(int root) {
    q.push(pii(root, 0));  // pair<나, 부모>
    while (true) {
        if (q.empty()) break;
        int now = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now].at(i);
            if (next == parent) continue;  // 이미 방문한 노드 패스
            depth[next] = depth[now] + 1;
            DP[next][0] = now;  // 부모 노드 저장
            h = max(h, depth[next]);  // tree의 depth 업데이트
            q.push(pii(next, now));
        }
    }

    return;
}

void setDP() {
    for (int j = 1; j <= log2(h); j++) {
        for (int i = 1; i <= n; i++) {
            DP[i][j] = DP[ DP[i][j-1] ][j-1];
        }
    }

    return;
}

int LCA(int x, int y) {
    if (depth[x] != depth[y]) {
        if (depth[x] > depth[y]) swap(x, y);
        int d = depth[y] - depth[x];
        for (int i = log2(d); i >= 0; i--) {
            if (d >= 1 << i) {
                y = DP[y][i];
                d-= 1 << i;
            }
        }
    }
    if (x == y) return x;
    int d = depth[x];
    for (int i = log2(d); i >= 0; i--) {
        if (DP[x][i] == DP[y][i]) continue;
        else {
            x = DP[x][i];
            y = DP[y][i];
        }
    }

    return DP[x][0];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    init();

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);
    setDP();

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }

    return 0;
}