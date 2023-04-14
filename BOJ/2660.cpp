// 230414
// BOJ 2660 회장뽑기
// Floyd-Warshall

#include <iostream>
#define INF 987654321
#define MAX 51
using namespace std;

int member[MAX][MAX];
int max_dist[MAX];
int N, x, y;

// 1점 - 모두와 친구
// 2점 - 모두와 친구 or 친구의 친구
// 3점 - 모두와 친구 or 친구의 친구 or 친구의 친구의 친구
// 제일 먼 사람과의 거리가 점수네

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            member[i][j] = INF;
        }
    }

    while (true) {
        cin >> x >> y;
        if (x == -1 && y == -1) break;
        member[x][y] = 1;
        member[y][x] = 1;
    }

    int min_value = INF;
    for (int k = 1; k <= N; k++) {
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= N; i++) {
                if (i == j) continue;
                if (member[i][j] > member[i][k] + member[k][j]) {
                    member[i][j] = member[i][k] + member[k][j];
                }
            }
        }
    }

    for (int j = 1; j <= N; j++) {
        int max_temp = 0;
        for (int i = 1; i <= N; i++) {
            if (i == j) continue;
            max_temp = max(max_temp, member[i][j]);
        }
        max_dist[j] = max_temp;
        min_value = min(min_value, max_dist[j]);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (max_dist[i] == min_value) cnt++;
    }

    cout << min_value << " " << cnt << "\n";
    for (int i = 1; i <= N; i++) {
        if (max_dist[i] == min_value) cout << i << " ";
    }

    return 0;
}