// 230302
// BOJ 18352 특정 거리의 도시 찾기

#include <iostream>
#include <vector>
#include <queue>
#define MAX 300001
#define INF 98765432100

using namespace std;


vector<int> v[MAX];
queue<int> q;
long long dist[MAX];
bool visited[MAX];
int N, M, K, X, a, b;
bool isExisted = false;

void init() {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    return;
}

void dijkstra() {
    q.push(X);
    dist[X] = 0;  // start node
    
    while (true) {
        if (q.empty()) break;
        int now = q.front();
        q.pop();
        if (visited[now]) continue;
        visited[now] = true;
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now].at(i);
            // update the shortest distance
            if (dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K >> X;
    init();

    // create graph
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }

    dijkstra();

    // result
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            if (!isExisted) isExisted = true;
            cout << i << "\n";
        }
    }

    if (!isExisted) cout << -1;

    return 0;
}