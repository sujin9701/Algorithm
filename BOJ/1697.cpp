// 230322
// BOJ 1687 숨바꼭질
// bfs

#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

typedef pair<int, int> pii;

queue<pii> q;
bool isVisited[MAX];

int N, K, res;

bool check(int n) {
    if (n < 0 || n > 100000 || isVisited[n]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    q.push(pii(N, 0));
    
    // bfs
    while (true) {
        if (q.empty()) break;
        pii now = q.front();
        q.pop();
        if (now.first == K) {
            cout << now.second;
            break;
        }
        int next[3] = {now.first + 1, now.first - 1, now.first * 2};
        for (int i = 0; i < 3; i++) {
            if (check(next[i])) {
                isVisited[next[i]] = true;
                q.push(pii(next[i], now.second + 1));
            }
        }
    }

    return 0;
}