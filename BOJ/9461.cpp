// 230411
// BOJ 9461 파도반 수열
// DP

#include <iostream>
#define MAX 101
using namespace std;

long long ary[MAX] = {0, 1, 1, 1, 2, 2};
int T, n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 6; i <= 100; i++) {
        ary[i] = ary[i - 5] + ary[i - 1];
    }

    cin >> T;
    while (T--) {
        cin >> n;
        cout << ary[n] << "\n";
    }

    return 0;
}