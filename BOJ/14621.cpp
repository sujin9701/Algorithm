// 230305
// BOJ 14621 나만 안되는 연애
// MST - Prim

#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
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
char gender[MAX];  // M or W
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
    
    for (int i = 1; i <= n; i++) {
        cin >> gender[i];
    }

    // create graph
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (gender[a] == gender[b]) continue;  // 남초~여초 도로만 받도록
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

    // 그래프가 완성되었는지 확인
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!isVisited[i]) {
            flag = false;
            break;
        }
    }

    if (flag) cout << sum;
    else cout << -1;

    return 0;
}