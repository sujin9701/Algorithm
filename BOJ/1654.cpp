// 230317
// BOJ 1654 랜선 자르기
// Binary Search

#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

long long ary[MAX];
int k, n;
long long mini = 1, maxi = 1, mid, res = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> ary[i];
        maxi = max(maxi, ary[i]);
    }
    
    mid = (mini + maxi) / 2;
    int cnt;
    while (true) {
        cnt = 0;
        if (mini > maxi) break;
        for (int i = 0; i < k; i++) {
            cnt += ary[i] / mid;
        }
        if (cnt < n) {
            maxi = mid - 1;
            mid = (mini + maxi) / 2;
        }
        else {  // cnt >= n
            res = max(res, mid);
            mini = mid + 1;
            mid = (mini + maxi) / 2;
        }
    }

    cout << res << "\n";

    return 0;
}