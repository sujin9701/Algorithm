// 230330
// BOJ 16236 아기 상어
// Simulation

#include <iostream>
#include <queue>
#define MAX 21
#define INF 987654321
using namespace std;

struct Fish {
    int x, y, d;
};

queue<Fish> q;
int N, sx, sy, baby = 2, cnt = 2, sec = 0;
int sea[MAX][MAX];
bool visited[MAX][MAX] = {false, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    return;
}

void simulation(int x, int y) {
    init();  // 방문 여부 초기화
    Fish minF = {x, y, INF};  // 먹을 물고기 초기값

    // 아기 상어 위치에서 출발
    visited[x][y] = true;
    q.push({x, y, 0});

    while (true) {
        if (q.empty()) break;
        Fish cur = q.front();
        q.pop();

        // 현재 위치에 물고기가 있는지
        // 그렇담 먹을 수 있는 물고기 후보인지 확인
        if (sea[cur.x][cur.y] > 0 && sea[cur.x][cur.y] < baby) {
            if (cur.d < minF.d) minF = cur;
            else if (cur.d == minF.d) {
                if (cur.y < minF.y) minF = cur;
                else if (cur.y == minF.y && cur.x < minF.x) minF = cur;
            }
            else continue;  // 상하좌우 확인해봤자 minF.d보다 커짐
        }

        // 더 확인해야 하면 상하좌우 확인 (물고기가 없는 자리인 경우)
        // 현재 위치에 후보가 있다면 더 확인할 필요가 없음 왜냐면 d가 늘어나니까
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) continue;  // 범위 체크
            if (visited[nx][ny]) continue;  // 이미 지나간 자리
            if (sea[cur.x][cur.y] > baby) continue;  // 못 지나가는 자리

            visited[nx][ny] = true;
            q.push({nx, ny, cur.d + 1});
        }
    }

    // 먹을 물고기를 찾았다면 걔 먹고 또 먹을 애 찾기
    if (minF.d != INF) {
        sec += minF.d;
        cnt--;
        if (cnt == 0) {
            baby++;
            cnt = baby;
        }
        sea[minF.x][minF.y] = 0;
        simulation(minF.x, minF.y);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            cin >> sea[i][j];
            if (sea[i][j] == 9) {
                sx = i, sy = j;
                sea[i][j] = 0;
            }
        }
    }

    simulation(sx, sy);
    cout << sec;

    return 0;
}