// 2340410
// BOJ 16139 인간-컴퓨터 상호작용

#include <iostream>
#include <string>
#define MAX 200005
using namespace std;

string s;
int save_data[26][MAX];
char a;
int q, l, r;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

    save_data[s[0] - 'a'][0]++;
    for (int j = 1; j < s.length(); j++) {
        save_data[s[j] - 'a'][j]++;
        for (int i = 0; i < 26; i++) {
            save_data[i][j] += save_data[i][j - 1];
        }
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> l >> r;
        cout << save_data[a - 'a'][r] - save_data[a - 'a'][l - 1] << "\n";
    }

    return 0;
}