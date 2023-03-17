// 230317
// Binary Search 기본 코드

#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int ary[MAX];
int n, k, mini, maxi, mid;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> ary[i];
    }
    sort(ary, ary + n);

    mini = 0, maxi = n - 1;
    bool flag = false;
    while (true) {
        mid = (mini + maxi) / 2;
        if (mini > maxi) break;
        if (ary[mid] == k) {
            flag = true;
            break;
        }
        else if (ary[mid] > k) maxi = mid - 1;
        else mini = mid + 1;
    }
    
    if (flag) cout << "TRUE";
    else cout << "FALSE";


    return 0;
}