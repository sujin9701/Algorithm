// 230410
// BOJ 2231 분해합

#include <iostream>
using namespace std;

int div_num[6] = {1000000, 100000, 10000, 1000, 100, 10};
int n, temp, res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    // 가장 작은 생성자 구하기
    for (int i = 1; i < n; i++) {
        temp = i;
        res = i;
        for (int j = 0; j < 6; j++) {
            if (temp / div_num[j] == 0) continue;
            res += temp / div_num[j];
            temp -= (temp / div_num[j]) * div_num[j];
        }
        res += temp;
        if (n == res) {
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}