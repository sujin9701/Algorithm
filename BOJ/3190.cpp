// 230412
// BOJ 3190 뱀
// Simulation

#include <iostream>
#include <deque>
#define MAX 101
using namespace std;

typedef pair<int, int> pii;

bool apple[MAX][MAX];
bool map[MAX][MAX];
deque<pii> snake;
int turn[10001];

int N, K, L, x, y, dir = 1, sec = 0;
char d;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool check_range(int x, int y) {
    if (x < 1 || x > N || y < 1 || y > N) return false;
    return true;
}

void play() {
    snake.push_back(pii(1, 1));
    map[1][1] = true;
    while (true) {
        sec++;

        int nx = snake.back().first + dx[dir];
        int ny = snake.back().second + dy[dir];

        // 종료 조건
        if (!check_range(nx, ny)) break;
        if (map[nx][ny]) break;

        // 뱀 머리 위치 업데이트
        map[nx][ny] = true;
        snake.push_back(pii(nx, ny));
        if (apple[nx][ny]) apple[nx][ny] = false;
        else {
            int del_x = snake.front().first;
            int del_y = snake.front().second;
            map[del_x][del_y] = false;
            snake.pop_front();
        }

        dir = (dir + turn[sec]) % 4;
        if (dir == -1) dir = 3;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> y >> x;
        apple[x][y] = true;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> x >> d;
        if (d == 'D') turn[x] = 1;
        else turn[x] = -1;
    }

    play();

    cout << sec;

    return 0;
}