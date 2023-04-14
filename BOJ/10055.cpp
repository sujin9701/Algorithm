// 230414
// BOJ 11055 가장 큰 증가하는 부분 수열
// DP

#include <iostream>
#define MAX 1002
using namespace std;

// 나보다 작은애들 중에서
// 나의 DP = 걔 위치의 DP + 나의 ary값 vs 나의 현재 DP 더 큰 것

int ary[MAX];
int DP[MAX];
int N, max_sum = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> ary[i];
    
    DP[1] = ary[1];
    max_sum = DP[1];
    for (int i = 2; i <= N; i++) {
        DP[i] = ary[i];
        for (int j = i - 1; j > 0; j--) {
            if (ary[i] > ary[j]) {
                DP[i] = max(DP[i], DP[j] + ary[i]);
            }
        }
        max_sum = max(max_sum, DP[i]);
    }

    cout << max_sum;

    return 0;
}