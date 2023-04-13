// 230413
// BOJ 2870 수학숙제
// 문자열, 정렬, 파싱

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 102
using namespace std;

vector<string> s;
vector<string> v[MAX];

string input_data;
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;

    // 입력받으면서 숫자만 따로 저장하기
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> input_data;
        temp = "";
        for (int j = 0; j < input_data.length(); j++) {
            if (input_data[j] >= '0' && input_data[j] <= '9') {
                temp.push_back(input_data[j]);
            }
            else {
                if (temp.length() > 0) s.push_back(temp);
                temp = "";
            }
        }
        if (temp.length() > 0) s.push_back(temp);
    }

    // 맨 앞에 0 없애기
    for (int i = 0; i < s.size(); i++) {
        while (true) {
            if (s[i].at(0) == '0' && s[i].length() > 1) s[i].erase(0, 1);
            else break;
        }
    }

    // 문자열 정렬
    sort(s.begin(), s.end());

    // 길이별로 집어넣기
    for (int i = 0; i < s.size(); i++) {
        v[s[i].length()].push_back(s[i]);
    }
    
    // 짧은 것부터 출력하면 오름차순 정렬 가능
    for (int i = 1; i <= 100; i++) {
        if (v[i].empty()) continue;
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i].at(j) << "\n";
        }
    }

    return 0;
}