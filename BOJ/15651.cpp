// 230404
// BOJ 15651 N과 M (3)
// Backtracking

#include <iostream>
#define MAX 8
using namespace std;

bool ary[MAX][MAX] = {false, };
int res[MAX];
int N, M;

void backtracking(int d) {
    if (d == M) {
        for (int i = 0; i < M; i++) cout << res[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!ary[d][i]) {
            res[d] = i;
            ary[d][i] = true;
            backtracking(d+1);
            ary[d][i] = false;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    backtracking(0);

    return 0;
}