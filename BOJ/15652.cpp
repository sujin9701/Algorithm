// 230404
// BOJ 15652 N과 M (4)
// Backtracking

#include <iostream>
#define MAX 9
using namespace std;

int N, M;
bool ary[MAX][MAX];
int res[MAX];

void backtracking(int d, int s) {
    if (d == M) {
        for (int i = 0; i < M; i++) cout << res[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = s; i <= N; i++) {
        if (!ary[d][i]) {
            ary[d][i] = true;
            res[d] = i;
            backtracking(d+1, i);
            ary[d][i] = false;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    backtracking(0, 1);

    return 0;
}