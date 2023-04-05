// 230405
// BOJ 21610 마법사 상어와 비바라기
// Simulation

#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

struct Order {
    int d, s;
};

struct Cloud {
    int x, y;
};

queue<Cloud> q;
int basket[MAX][MAX];
bool isExist[MAX][MAX];
Order order[101];
int N, M, d, s;

// 구름 이동시킬 때
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

// 물복사 체크할 때
int dx2[4] = {-1, 1, 1, -1};
int dy2[4] = {-1, -1, 1, 1};


void moveAndRain(Cloud now, int d, int s) {
    // 구름 이동
    int nx = now.x;
    int ny = now.y;
    for (int i = 0; i < s; i++) {
        nx += dx[d];
        ny += dy[d];
        if (nx > N) nx = 1;
        else if (nx < 1) nx = N;
        if (ny > N) ny = 1;
        else if (ny < 1) ny = N;
    }

    // 비 내리기
    basket[nx][ny]++;
    isExist[nx][ny] = true;

    return;
}

bool checkRange(int x, int y) {
    if (x < 1 || x > N || y < 1 || y > N) return false;
    return true;
}

void copyWater() {
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            if (isExist[i][j]) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx2[k];
                    int ny = j + dy2[k];
                    if (checkRange(nx, ny) && basket[nx][ny] > 0) {
                        cnt++;
                    }
                }
                basket[i][j] += cnt;
            }
        }
    }
    return;
}

void removeAndMake() {
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            if (isExist[i][j]) isExist[i][j] = false;
            else {
                if (basket[i][j] >= 2) {
                    basket[i][j] -= 2;
                    q.push({i, j});
                }
            }
        }
    }
    return;
}

void magic(int d, int s) {
    int realS = s % N;
    while (true) {
        if (q.empty()) break;
        Cloud now = q.front();
        q.pop();
        moveAndRain(now, d, realS);
    }
    copyWater();
    removeAndMake();

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            cin >> basket[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> d >> s;
        order[i] = {d, s};
    }

    q.push({1, N});
    q.push({2, N});
    q.push({1, N-1});
    q.push({2, N-1});
    for (int i = 0; i < M; i++) {
        magic(order[i].d, order[i].s);
    }

    int sum = 0;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            sum += basket[i][j];
        }
    }
    cout << sum;

    return 0;
}