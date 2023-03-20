// 230320
// BOJ 11399 ATM
// Greedy Algorithm


#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int p[MAX];
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p, p+n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += p[i] * (n-i);
    }

    cout << sum;

    return 0;
}