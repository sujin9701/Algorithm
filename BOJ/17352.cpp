// 230303
// BOJ 17352 여러분의 다리가 되어드리겠습니다!

#include <iostream>
#define MAX 300001

using namespace std;

int root[MAX];
int n, a, b;

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

    cin >> n;
    init();

    for (int i = 0; i < n - 2; i++) {
        cin >> a >> b;
        uni(a, b);
    }

    cout << 1 << " ";  // root[1] = 1
    for (int i = 2; i <= n; i++) {
        if (find(i) != 1) {
            cout << root[i];
            break;
        }
    }

    return 0;
}