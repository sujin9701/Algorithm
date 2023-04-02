// 230330
// BOJ 15650 N과 M (2)
// Backtracking

#include <iostream>
#define MAX 9
using namespace std;

int arr[MAX];
bool visited[MAX];
int N, M;

void backtracking(int start, int d) {
    if (d == M) {  // 종료 조건
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[d] = i;
            backtracking(i + 1, d + 1);
            visited[i] = false;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    backtracking(1, 0);

    return 0;
}