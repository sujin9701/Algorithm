// 230413
// BOJ 2579 계단 오르기
// DP

#include <iostream>
#define MAX 301
using namespace std;

int stair[MAX];
int DP[MAX];
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> stair[i];

    DP[1] = stair[1];
    DP[2] = stair[1] + stair[2];

    for (int i = 3; i <= n; i++) {
        DP[i] = max(DP[i - 2], DP[i - 3] + stair[i - 1]) + stair[i];
    }

    cout << DP[n];

    return 0;
}