// 2340410
// BOJ 2559 수열
// 누적합

#include <iostream>
using namespace std;

int ary[100001];
int n, k, p1, p2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> ary[i];
    }

    int max_sum = 0;
    // 최댓값의 초기값
    for (int i = 0; i < k; i++) {
        max_sum += ary[i];
    }

    p1 = 0; p2 = k;
    int temp_max_sum = max_sum;
    while (p2 < n) {
        temp_max_sum -= ary[p1];
        temp_max_sum += ary[p2];
        if (temp_max_sum > max_sum) max_sum = temp_max_sum;
        p1++;
        p2++;
    }

    cout << max_sum;

    return 0;
}