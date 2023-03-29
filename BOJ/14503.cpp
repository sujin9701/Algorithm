// 230329
// BOJ 14503 로봇 청소기
// Simulation

#include <iostream>
#define MAX 52
using namespace std;

typedef pair<int, int> pii;

int room[MAX][MAX];
int N, M, x, y, dir, cnt = 0;

void init() {
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= M; i++) {
            room[i][j] = 0;
        }
    }

    return;
}

void work() {
    int dx[4] = {0, 1, 0, -1};  // 북, 동, 남, 서
    int dy[4] = {-1, 0, 1, 0};
    int nx, ny;

    while (true) {
        if (room[x][y] == 0) {
            room[x][y] = 2;
            cnt++;
        }
        // 사방이 깨끗한 경우
        if (room[x][y-1] && room[x][y+1] && room[x-1][y] && room[x+1][y]) {
            nx = x - dx[dir];
            ny = y - dy[dir];
            if (room[nx][ny] != 1) {  // 후진 가능하면 후진
                x = nx;
                y = ny;
            }
            else return;
        }
        // 더러운 칸 있는 경우
        else {
            while (true) {
                // 반시계 90도 회전
                if (dir == 0) dir = 3;
                else dir--;
                // 앞칸이 더러우면 전진
                nx = x + dx[dir];
                ny = y + dy[dir];
                if (room[nx][ny] == 0) {
                    x = nx;
                    y = ny;
                    break;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    init();

    cin >> y >> x >> dir;
    y++; x++;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= M; i++) {
            cin >> room[i][j];
        }
    }

    work();

    cout << cnt;

    return 0;
}