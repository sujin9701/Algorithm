// BFS 기본 코드

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

vector<int> v[MAX];
bool visited[MAX];
int n, m, s, a, b;

void init() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    return;
}

void bfs(int s) {
    queue<int> q;
    q.push(s);

    while (true) {
        if (q.empty()) break;
        int now = q.front();
        q.pop();
        if (visited[now]) continue;
        visited[now] = true;
        cout << now << " ";
        for (int i = 0; i < v[now].size(); i++) {
            q.push(v[now].at(i));
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> s;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        // 양방향
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    init();
    bfs(s);

    return 0;
}