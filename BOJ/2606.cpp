// 230326
// BOJ 2606 바이러스
// BFS

#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

vector<int> v[MAX];
queue<int> q;
bool visited[MAX];
int n, m, a, b;

void init() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        v[i].clear();
    }

    return;
}

void bfs(int s) {
    visited[s] = true;
    q.push(s);

    while (true) {
        if (q.empty()) break;
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now].at(i);
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    init();

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(1);

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (visited[i]) cnt++;
    }

    cout << cnt;

    return 0;
}