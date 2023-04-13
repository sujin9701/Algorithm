// 230413
// BOJ 1920 수 찾기
// Binary Search

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int ary[MAX];
int n, m, x;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> ary[i];

    sort(ary, ary + n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;

        bool flag = false;
        int start = 0, mid = n / 2, end = n - 1;
        while (true) {
            if (start > end) break;
            if (x == ary[mid]) {
                flag = true;
                cout << 1 << "\n";
                break;
            }
            if (x > ary[mid]) {
                start = mid + 1;
                mid = (start + end) / 2;
            }
            else {
                end = mid - 1;
                mid = (start + end) / 2;
            }
        }

        if (!flag) cout << 0 << "\n";
    }


    return 0;
}