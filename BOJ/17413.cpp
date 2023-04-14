// 230414
// BOJ 17413 단어 뒤집기 2
// 문자열

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;
stack<char> stk;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    getline(cin, s);

    // 태그가 있다면 그대로 출력
    // 띄어쓰기 기준 각각 뒤집기
    bool isTag = false;  // tag 안에 있는 건지
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '<') {
            while (!stk.empty()) {
                cout << stk.top();
                stk.pop();
            }
            isTag = true;
            cout << s[i];
        }
        else if (s[i] == '>') {
            isTag = false;
            cout << s[i];
        }
        else if (s[i] == ' ') {
            if (isTag) {
                cout << s[i];
                continue;
            }
            while (!stk.empty()) {
                cout << stk.top();
                stk.pop();
            }
            cout << s[i];
        }
        else {
            if (isTag) cout << s[i];
            else stk.push(s[i]);
        }
    }

    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }

    return 0;
}