// 230303
// BOJ 1717 집합의 표현

#include <iostream>
#define MAX 1000001

using namespace std;

int n, m, flag, a, b;
int root[MAX];

void init() {
    for (int i = 0; i <= n; i++) {
        root[i] = i;
    }
    
    return;
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
        cin >> flag >> a >> b;
        if (flag == 0) {  // union
            uni(a, b);
        }
        else {  // find
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}