// 230410
// BOJ 1149 RGB거리
// DP

#include <iostream>
#define MAX 1001
using namespace std;

int color[MAX][3];
int DP[MAX][3];
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }

    for (int i = 0; i < 3; i++) {
        DP[0][i] = color[0][i];
    }

    for (int i = 1; i < n; i++) {
        DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + color[i][0];
        DP[i][1] = min(DP[i-1][0], DP[i-1][2]) + color[i][1];
        DP[i][2] = min(DP[i-1][0], DP[i-1][1]) + color[i][2];
    }

    int min_cost = min(DP[n-1][0], DP[n-1][1]);
    min_cost = min(min_cost, DP[n-1][2]);

    cout << min_cost;

    return 0;
}