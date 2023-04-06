// 230406
// BOJ 14501 퇴사
// Backtracking

#include <iostream>
#include <algorithm>
#define MAX 16
using namespace std;

struct Info {
    int t, p;
};

Info schedule[MAX];
bool visited[MAX];
int N, T, P, maxP = 0;

void dfs(int start, int price) {
    maxP = max(maxP, price);
    if (start > N) return;
    for (int i = start; i <= N; i++) {
        int lastDay = i + schedule[i].t - 1;
        if (lastDay <= N) {
            for (int j = i; j <= lastDay; j++) {
                visited[j] = true;
            }
            dfs(lastDay + 1, price + schedule[i].p);
            for (int j = i; j <= lastDay; j++) {
                visited[j] = false;
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T >> P;
        schedule[i] = {T, P};
    }

    dfs(1, 0);
    cout << maxP;

    return 0;
}