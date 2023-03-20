// 230320
// BOJ 1931 회의실 배정
// Greedy Algorithm

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

typedef pair<int, int> pii;

pii ary[MAX];  // pair<end, start>
pii temp;
int n, a, b, start = 0;  // 시작 가능 시간

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        temp.first = b;
        temp.second = a;
        ary[i] = temp;
    }

    sort(ary, ary + n);
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (start <= ary[i].second) {
            cnt++;
            start = ary[i].first;
        }
    }

    cout << cnt;

    return 0;
}