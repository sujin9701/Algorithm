// 230405
// BOJ 19236 청소년 상어
// Backtracking

#include <iostream>
#include <algorithm>
#define MAX 17
using namespace std;

struct Fish {
    int x, y, d;
    bool alive;
};

int sea[5][5];
Fish fishes[MAX];
int a, b, maxSum = 0;

int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};


void debugging() {
    for (int j = 1; j <= 4; j++) {
        for (int i = 1; i <= 4; i++) {
            cout << sea[i][j] << " " << fishes[sea[i][j]].d << "  ";
        }
        cout << "\n";
    }
    return;
}

bool checkRange(int x, int y) {
    if (x < 1 || x > 4 || y < 1 || y > 4) return false;
    return true;
}

bool isSharkPos(int x, int y, int sx, int sy) {
    if (x == sx && y == sy) return true;
    return false;
}

// 새 위치에 물고기 있으면 swap, 없으면 옮기기만
void swapFish(int x, int y, int nx, int ny) {
    int nowF = sea[x][y];
    int nextF = sea[nx][ny];
    sea[nx][ny] = nowF;
    sea[x][y] = nextF;
    fishes[nowF].x = nx;
    fishes[nowF].y = ny;
    if (nextF != 0) {  // 새 위치에 물고기가 있다면
        fishes[nextF].x = x;
        fishes[nextF].y = y;
    }

    return;
}

void moveFish(int idx, int sx, int sy) {
    // 현재 방향으로 이동이 가능한지 확인 (범위내에 & 상어X)
    // 가능하면 swap
    Fish now = fishes[idx];
    int nd = now.d;
    int nx = now.x + dx[nd];
    int ny = now.y + dy[nd];
    if (checkRange(nx, ny) && !isSharkPos(nx, ny, sx, sy)) {
        swapFish(now.x, now.y, nx, ny);
    }
    // 불가능하면 가능해질 때까지 돌리기 :: 가능해지는 순간 swap
    // 불가능하다면 안 옮기고 냅둘거야 :: 안 건드리면 될 듯
    else {
        for (int i = 0; i < 7; i++) {
            if (nd == 8) nd = 1;
            else nd++;
            nx = now.x + dx[nd];
            ny = now.y + dy[nd];
            if (checkRange(nx, ny) && !isSharkPos(nx, ny, sx, sy)) {
                fishes[idx].d = nd;
                swapFish(now.x, now.y, nx, ny);
                break;
            }
        }
    }

    return;
}

void dfs(int sx, int sy, int sd, int sum) {
    // 최댓값 업데이트 시도
    maxSum = max(maxSum, sum);

    // 현재 상태 임시 저장
    int cSea[5][5];
    Fish cFishes[MAX];
    for (int j = 1; j <= 4; j++) {
        for (int i = 1; i <= 4; i++) {
            cSea[i][j] = sea[i][j];
        }
    }
    for (int i = 1; i <= 16; i++) {
        cFishes[i] = fishes[i];
    }

    // 물고기 이동
    for (int i = 1; i <= 16; i++) {
        if (fishes[i].alive) moveFish(i, sx, sy);
    }

    //cout << maxSum << "\n";
    //debugging();


    // 상어 이동 가능 위치 여러 개
    //  - 물고기 먹고
    //  - dfs
    //  - 물고기 뱉고
    for (int i = 1; i <= 3; i++) {
        int nsx = sx + dx[sd] * i;
        int nsy = sy + dy[sd] * i;
        if (checkRange(nsx, nsy)) {
            int nowF = sea[nsx][nsy];
            if (nowF != 0) {
                int nsd = fishes[nowF].d;

                fishes[nowF].alive = false;
                sea[nsx][nsy] = 0;

                dfs(nsx, nsy, nsd, sum + nowF);

                fishes[nowF].alive = true;
                sea[nsx][nsy] = nowF;
            }
        }
        else break;
    }

    // 바다, 물고기 상태 원상복구
    for (int j = 1; j <= 4; j++) {
        for (int i = 1; i <= 4; i++) {
            sea[i][j] = cSea[i][j];
        }
    }
    for (int i = 1; i <= 16; i++) {
        fishes[i] = cFishes[i];
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int j = 1; j <= 4; j++) {
        for (int i = 1; i <= 4; i++) {
            cin >> a >> b;
            sea[i][j] = a;
            fishes[a] = {i, j, b, true};
        }
    }

    // 첫 번째 칸 물고기 먹기
    int now = sea[1][1];
    fishes[now].alive = false;
    sea[1][1] = 0;

    // 백트래킹
    dfs(1, 1, fishes[now].d, now);

    cout << maxSum;

    return 0;
}