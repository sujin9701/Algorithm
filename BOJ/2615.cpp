// 230414
// BOJ 2615 오목
// 구현

#include <iostream>
#define MAX 20
using namespace std;

int board[MAX][MAX];

// 오, 대각선아래, 아, 대각선위
int dx[4] = {1, 1, 0, 1};
int dy[4] = {0, 1, 1, -1};

bool check_range(int x, int y) {
    if (x < 1 || x > 19 || y < 1 || y > 19) return false;
    return true;
}

// 오른쪽, 아래, 대각선위, 대각선아래
// 이긴거 찾는 즉시 멈추기?
// 여섯 개 확인해야해 왜냐면 여섯번재도 같은거면 안되기 때문
// 범위 체크

bool find_winner(int sx, int sy) {
    int color = board[sx][sy];
    int nx, ny;
    // 세 방향에 대해서
    for (int i = 0; i < 4; i++) {
        bool flag = true;
        // 여기부터 다섯 개 확인할 거야
        for (int j = 1; j < 5; j++) {
            nx = sx + dx[i] * j;
            ny = sy + dy[i] * j;
            // 범위 벗어나면 다음 거 확인할 필요 X
            if (!check_range(nx, ny) || board[nx][ny] != color) {
                flag = false;
                break;
            }
        }

        // 다섯개 다 같아 :: 앞뒤 확인!!!
        if (flag) {
            // 앞
            int bx = sx - dx[i];
            int by = sy - dy[i];
            // 뒤
            int ax = sx + dx[i] * 5;
            int ay = sy + dy[i] * 5;
            // 찾았다!
            if ((!check_range(bx, by) || board[bx][by] != color) && (!check_range(ax, ay) || board[ax][ay] != color)) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int j = 1; j <= 19; j++) {
        for (int i = 1; i <= 19; i++) {
            cin >> board[i][j];
        }
    }

    for (int j = 1; j <= 19; j++) {
        for (int i = 1; i <= 19; i++) {
            // 바둑돌이 있는 경우에만 확인 시작
            if (board[i][j] != 0) {
                if (find_winner(i, j)) {
                    cout << board[i][j] << "\n" << j << " " << i;
                    return 0;
                }
            }
        }
    }

    cout << 0;

    return 0;
}