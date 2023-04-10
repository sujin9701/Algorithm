// 230410
// BOJ 1325 효율적인 해킹
// BFS

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

vector<int> v[MAX];
queue<int> q;
bool visited[MAX];
int hacking[MAX];
int n, m, a, b;

void init() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    return;
}

void bfs(int start_num) {
    int depth = 0;
    visited[start_num] = true;
    q.push(start_num);
    while (true) {
        if (q.empty()) break;
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            if (visited[v[now].at(i)]) continue;
            visited[v[now].at(i)] = true;
            depth++;
            q.push(v[now].at(i));
        }
    }
    
    hacking[start_num] = depth;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }
    
    int max_hacking = 0;
    for (int i = 1; i <= n; i++) {
        init();
        bfs(i);
        max_hacking = max(max_hacking, hacking[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (hacking[i] == max_hacking) cout << i << " ";
    }

    return 0;
}