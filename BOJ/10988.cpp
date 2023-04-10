// 230410
// BOJ 10988 팰린드롬인지 확인하기
// 구현

#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;
    int slen = s.length();
    for (int i = 0; i < slen; i++) {
        if (s[i] != s[slen - i - 1]) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;

    return 0;
}