// 230301
// Dijkstra 기본 코드

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 101

using namespace std;

// save node info
struct Data {
    int node;
    int weight;
    Data(int node, int weight): node(node), weight(weight) {};
    bool operator < (const Data d) const {
        return weight > d.weight;
    }
};

vector<Data> v[MAX];
int dist[MAX];
bool visited[MAX];
priority_queue<Data> pq;

int N, M, a, b, c;

// initialization
void init() {
    for (int i = 1; i <= N; i++) {
        v[i].clear();
        dist[i] = INF;
        visited[i] = false;
    }

    return;
}

void dijkstra() {
    // start node: 1
    dist[1] = 0;
    pq.push(Data(1, 0));

    while (true) {
        if (pq.empty()) break;
        Data now = pq.top();
        pq.pop();
        if (visited[now.node]) continue;
        visited[now.node] = true;
        for (int i = 0; i < v[now.node].size(); i++) {
            Data next = v[now.node].at(i);
            if (dist[next.node] > dist[now.node] + next.weight) {
                dist[next.node] = dist[now.node] + next.weight;
                pq.push(Data(next.node, dist[next.node]));
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    init();

    // create graph
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        v[a].push_back(Data(b, c));
        v[b].push_back(Data(a, c));  // required for bi-directional graphs
    }

    dijkstra();

    for (int i = 1; i <= N; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}