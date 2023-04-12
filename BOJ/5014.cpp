// 230412
// BOJ 5014 스타트링크
// BFS...

#include <iostream>
#include <queue>
#define MAX 1000005
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;

queue<pii> q;
bool visited[MAX];
int F, S, G, U, D, min_cnt = INF;

bool check_range(int now) {
    if (now < 1 || now > F) return false;
    return true;
}

void find_goal() {
    if (S == G) {
        min_cnt = 0;
        return;
    }
    
    visited[S] = true;
    q.push(pii(S, 0));
    while (true) {
        if (q.empty()) break;
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now == G) {
            min_cnt = min(min_cnt, cnt);
        }

        if (check_range(now + U) && !visited[now + U]) {
            visited[now + U] = true;
            q.push(pii(now + U, cnt + 1));
        }
        if (check_range(now - D) && !visited[now - D]) {
            visited[now - D] = true;
            q.push(pii(now - D, cnt + 1));
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> F >> S >> G >> U >> D;

    find_goal();

    if (min_cnt == INF) cout << "use the stairs";
    else cout << min_cnt;

    return 0;
}