// 230414
// BOJ 2668 숫자고르기
// bfs

#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

queue<int> q;
int ary[MAX];
bool visited[MAX];
bool res[MAX];
int N;

void init() {
    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }
    return;
}

bool bfs(int start) {
    visited[start] = true;
    q.push(start);

    while (true) {
        if (q.empty()) break;
        int now = q.front();
        q.pop();
        int next = ary[now];
        // 이미 찾아낸 사이클에 포함될 경우 true를 return해주어야 함
        if (visited[next]) {
            if (start == next) return true;
            else return false;
        }
        else {
            visited[next] = true;
            q.push(next);
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> ary[i];
    }
    
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        init();
        if (bfs(i)) {
            cnt++;
            res[i] = true;
        }
    }
    
    cout << cnt << "\n";
    for (int i = 1; i <= N; i++) {
        if (res[i]) cout << i << "\n";
    }

    return 0;
}