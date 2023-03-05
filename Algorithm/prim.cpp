// 230305
// Prim 기본 코드
// BOJ 1197 최소 스패닝 트리

#include <iostream>
#include <vector>
#include <queue>
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
bool isVisited[MAX];
int n, m, a, b, c;

void init() {
    for (int i = 1; i <= n; i++) {
        v[i].clear();
        isVisited[i] = false;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    init();

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back(Data(b, c));
        v[b].push_back(Data(a, c));
    }

    isVisited[1] = true;
    for (int i = 0; i < v[1].size(); i++) {
        pq.push(v[1].at(i));
    }

    int sum = 0;
    while (true) {
        if (pq.empty()) break;
        Data now = pq.top();
        pq.pop();
        if (isVisited[now.node]) continue;
        isVisited[now.node] = true;
        sum += now.weight;
        for (int i = 0; i < v[now.node].size(); i++) {
            pq.push(v[now.node].at(i));
        }
    }

    cout << sum;

    return 0;
}