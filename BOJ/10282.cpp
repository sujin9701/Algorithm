// 230412
// BOJ 10282 해킹
// Dijkstra

#include <iostream>
#include <vector>
#include <queue>
#define INF 9876543210
#define MAX 10001
using namespace std;

struct Data {
    int node, weight;
    Data(int node, int weight): node(node), weight(weight) {};
    bool operator < (const Data d) const {
        return weight > d.weight;
    }
};

vector<Data> v[MAX];
priority_queue<Data> pq;
bool visited[MAX];
long long dist[MAX];

int T, n, d, c, a, b, s;

void init() {
    for (int i = 0; i <= n; i++) {
        v[i].clear();
        visited[i] = false;
        dist[i] = INF;
    }
    return;
}

void hacking(int start_num) {
    dist[start_num] = 0;
    pq.push({start_num, 0});

    int last;

    while (true) {
        if (pq.empty()) break;
        Data now = pq.top();
        pq.pop();
        if (visited[now.node]) continue;
        visited[now.node] = true;
        last = now.node;
        for (int i = 0; i < v[now.node].size(); i++) {
            Data next = v[now.node].at(i);
            if (dist[next.node] > dist[now.node] + next.weight) {
                dist[next.node] = dist[now.node] + next.weight;
                pq.push(Data(next.node, dist[next.node]));
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) cnt++;
    }
    cout << cnt << " " << dist[last] << "\n";

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> n >> d >> c;
        init();

        for (int i = 0; i < d; i++) {
            cin >> a >> b >> s;
            v[b].push_back({a, s});
        }
        hacking(c);
    }

    return 0;
}