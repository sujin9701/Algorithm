// 230414
// BOJ 11403 경로 찾기
// Floyd-Warshall

#include <iostream>
#define MAX 101
using namespace std;

int map[MAX][MAX];
int N;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            cin >> map[i][j];
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= N; i++) {
                if (map[i][k] == 1 && map[k][j] == 1) map[i][j] = 1;
            }
        }
    }

    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}