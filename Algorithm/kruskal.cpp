// 230305
// Kruskal 기본 코드
// BOJ 1197 최소 스패닝 트리

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10001  // node 기준
using namespace std;

typedef pair<int, int> pii;

pair<int, pii> p;  // <weight, <firstNode, secondNode>>
vector<pair<int, pii>> v;
int root[MAX];
int n, m, a, b, c;

void init() {
    v.clear();
    for (int i = 1; i <= n; i++) {
        root[i] = i;
    }
}

int find(int x) {
    if (x == root[x]) return x;
    return root[x] = find(root[x]);
}

void uni(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        if (rx > ry) swap(rx, ry);
        root[ry] = rx;
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
        p.first = c;
        p.second = pii(a, b);
        v.push_back(p);
    }

    sort(v.begin(), v.end());  // weight 기준 오름차순 정렬

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        p = v.at(i);
        if (find(p.second.first) == find(p.second.second)) continue;
        uni(p.second.first, p.second.second);
        sum += p.first;
    }

    cout << sum;

    return 0;
}