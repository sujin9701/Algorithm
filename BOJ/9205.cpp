// 230325
// BOJ 9205 맥주 마시면서 걸어가기
// BFS

#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#define MAX 105
using namespace std;

typedef pair<int, int> pii;

queue<pii> q;
pii store[MAX];
bool visited[MAX];
int T, n, x, y;

void init() {
    for (int i = 0; i < n + 2; i++) {
        visited[i] = false;
    }

    return;
}

int calculate(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

void bfs() {
    q.push(pii(store[0].first, store[0].second));

    while (true) {
        if (q.empty()) break;
        
        pii now = q.front();
        q.pop();
        if (now.first == store[n+1].first && now.second == store[n+1].second) {
            cout << "happy\n";
            return;
        }

        for (int i = 1; i < n+2; i++) {
            if (visited[i]) continue;
            pii next = store[i];
            int dist = calculate(now.first, now.second, next.first, next.second);
            if (dist <= 1000) {
                visited[i] = true;
                q.push(next);
            }
        }
    }
    cout << "sad\n";
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        init();

        for (int i = 0; i < n+2; i++) {
            cin >> x >> y;
            store[i] = pii(x, y);
        }
        
        bfs();
    }

    return 0;
}