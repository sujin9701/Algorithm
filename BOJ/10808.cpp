// 230410
// BOJ 10808 알파벳 개수
// 구현

#include <iostream>
#include <string>
using namespace std;

string s;
int cnt_ary[26];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        cnt_ary[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << cnt_ary[i] << " ";
    }

    return 0;
}