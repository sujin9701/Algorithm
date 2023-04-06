// 230406
// BOJ 13458 시험 감독
// 사칙연산..

#include <iostream>
#define MAX 1000001
using namespace std;

int room[MAX];
int N, a, b, c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> room[i];
    }
    cin >> b >> c;

    long long cnt = N;
    for (int i = 0; i < N; i++) {
        room[i] -= b;
        if (room[i] > 0) {
            int sub = room[i] / c;
            cnt += sub;
            room[i] -= sub * c;
            if (room[i] > 0) cnt++;
        }
    }

    cout << cnt;

    return 0;
}