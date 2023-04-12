// 230412
// BOJ 1406 에디터
// stack

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;
int m;
char command, add;
stack<char> left_s;
stack<char> right_s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        left_s.push(s[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> command;
        if (command == 'L') {
            if (left_s.empty()) continue;
            right_s.push(left_s.top());
            left_s.pop();
        }
        else if (command == 'D') {
            if (right_s.empty()) continue;
            left_s.push(right_s.top());
            right_s.pop();
        }
        else if (command == 'B') {
            if (left_s.empty()) continue;
            left_s.pop();
        }
        else {
            cin >> add;
            left_s.push(add);
        }
    }

    while (!left_s.empty()) {
        right_s.push(left_s.top());
        left_s.pop();
    }
    while (!right_s.empty()) {
        cout << right_s.top();
        right_s.pop();
    }

    return 0;
}