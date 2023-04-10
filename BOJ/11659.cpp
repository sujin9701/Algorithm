// 230410
// BOJ 11659 구간 합 구하기 4
// 구간합

#include <iostream>
#define MAX 100001
using namespace std;

int n, m, temp, s, e;
int ary[MAX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        ary[i] = ary[i - 1] + temp;
    }

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        int sum = ary[e] - ary[s - 1];
        cout << sum << "\n";
    }

    return 0;
}