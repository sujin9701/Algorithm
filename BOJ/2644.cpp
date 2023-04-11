// 230411
// BOJ 2644 촌수계산
// DFS

#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

vector<int> v[MAX];
bool visited[MAX];
int n, m, f1, f2, x, y, flag;

void dfs(int now, int depth) {
    if (now == f2) {
        flag = true;
        cout << depth;
        return;
    }

    for (int i = 0; i < v[now].size(); i++) {
        int next = v[now].at(i);
        if (visited[next]) continue;
        visited[next] = true;
        dfs(next, depth+1);
        visited[next] = false;
        if (flag) return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> f1 >> f2 >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    flag = false;
    visited[f1] = true;
    dfs(f1, 0);

    if (!flag) cout << -1;

    return 0;
}