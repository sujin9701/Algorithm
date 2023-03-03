// 230303
// Union Find 기본 코드

#include <iostream>
#define MAX 101

using namespace std;

int root[MAX];
int n, m, a, b;

void init() {
    for (int i = 1; i <= n; i++) {
        root[i] = i;
    }

    return;
}

int find(int x) {
    if (root[x] == x) return x;
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
        cin >> a >> b;
        uni(a, b);
    }

    for (int i = 1; i <= n; i++) {
        cout << root[i] << " ";
    }

    return 0;
}