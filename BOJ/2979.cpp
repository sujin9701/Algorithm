// 230410
// BOJ 2979 트럭 주차
// 구현

#include <iostream>
using namespace std;

int a, b, c, s, e;
bool ary[3][101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++) {
        cin >> s >> e;
        for (int j = s; j < e; j++) {
            ary[i][j] = true;
        }
    }

    int total_fee = 0;
    for (int i = 1; i <= 100; i++) {
        int cnt = ary[0][i] + ary[1][i] + ary[2][i];
        if (cnt == 3) total_fee += c * 3;
        else if (cnt == 2) total_fee += b * 2;
        else if (cnt == 1) total_fee += a;
        else continue;
    }

    cout << total_fee;

    return 0;
}