// 230410
// BOJ 1159 농구 경기
// 구현

#include <iostream>
#include <string>
using namespace std;

int n;
string name;
int ary[26];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        ary[name[0] - 'a']++;
    }
    
    bool flag = false;
    for (int i = 0; i < 26; i++) {
        if (ary[i] >= 5) {
            flag = true;
            cout << char(i+'a');
        }
    }

    if (!flag) cout << "PREDAJA";

    return 0;
}