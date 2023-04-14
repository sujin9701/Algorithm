// 230414
// BOJ 16398 행성 연결
// MST - Kruskal

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

vector<pip> v;
int cost[MAX][MAX];
int parent[MAX];
bool visited[MAX];
int N, a, b, c;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) parent[px] = py;

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;    
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int j = 1; j <= N; j++) {
        for (int i = j + 1; i <= N; i++) {
            v.push_back(pip(cost[i][j], pii(i, j)));
        }
    }

    sort(v.begin(), v.end());
    
    long long min_cost = 0;
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (cnt == N - 1) break;
        pip now = v.at(i);
        // 만약 두 노드가 연결되어있지 않다면
        if (find(now.second.first) != find(now.second.second)) {
            uni(now.second.first, now.second.second);
            min_cost += now.first;
            cnt++;
        }
    }

    cout << min_cost;

    return 0;
}