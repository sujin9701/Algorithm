// 230414
// BOJ 15654 N과 M (5)
// Backtracking

#include <iostream>
#include <algorithm>
using namespace std;

int ary[9];
int res[9];
bool visited[9];
int N, M;

void backtracking(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            res[depth] = ary[i];
            backtracking(depth + 1);
            visited[i] = false;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> ary[i];
    
    sort(ary, ary + N);

    backtracking(0);

    return 0;
}