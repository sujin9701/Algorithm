// 230401
// BOJ 23290 마법사 상어와 복제
// Simulation

#include <iostream>
#include <vector>
using namespace std;

vector<int> fish[5][5];
vector<int> copied[5][5];
int smell[5][5] = {0, };
int tempRoute[3], route[3];

// 물고기 회전  :: d를 인덱스로 저장
int fdx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int fdy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

// 상어 이동 :: 상-좌-하-우 순서로 확인
int sdx[4] = {0, -1, 0, 1};
int sdy[4] = {-1, 0, 1, 0};

int M, S, fx, fy, d, sx, sy;
int maxCnt;

// 복제된 물고기만 저장할 배열 초기화
void init() {
    for (int j = 1; j <= 4; j++) {
        for (int i = 1; i <= 4; i++) {
            copied[i][j].clear();
        }
    }

    return;
}

// 4*4 범위 체크
bool checkRange(int x, int y) {
    if (x < 1 || x > 4 || y < 1 || y > 4) return false;
    return true;
}

// 물고기가 해당 위치로 이동할 수 있는지 확인
bool isMovable(int x, int y) {
    if (!checkRange(x, y)) return false;
    else if (smell[x][y] > 0) return false;
    else if (x == sx && y == sy) return false;
    return true;
}

// 물고기 복제할 위치 결정
void turnAndCopy(int x, int y, int d) {
    int nx = x + fdx[d];
    int ny = y + fdy[d];
    // 현재 방향으로 이동할 수 있다면 방향 그대로 이동
    if (isMovable(nx, ny)) {
        copied[nx][ny].push_back(d);
        return;
    }
    // 아니면 돌리면서 확인
    else {
        for (int i = 0; i < 8; i++) {
            if (d == 1) d = 8;
            else d--;
            nx = x + fdx[d];
            ny = y + fdy[d];
            if (isMovable(nx, ny)) {
                copied[nx][ny].push_back(d);
                return;
            }
        }
        // 모든 방향으로 이동할 수 없다면 제자리에 복사
        copied[x][y].push_back(d);
        return;
    }
}

// 물고기 복제 + 방향 찾아서 이동
void copyFish() {
    init();
    for (int j = 1; j <= 4; j++) {
        for (int i = 1; i <= 4; i++) {
            vector<int> now = fish[i][j];
            if (now.empty()) continue;
            for (int k = 0; k < now.size(); k++) {
                turnAndCopy(i, j, now.at(k));
            }
        }
    }

    return;
}

// 해당 경로로 이동했을 때 먹을 수 있는 물고기 수 구하기
int simulation() {
    bool visited[5][5] = {false, };  // 이미 방문한 곳은 물고기 수를 더하면 안 됨
    int x = sx;
    int y = sy;
    int cntFish = 0;
    for (int i = 0; i < 3; i++) {
        int dir = tempRoute[i];
        int nx = x + sdx[dir];
        int ny = y + sdy[dir];
        if (!checkRange(nx, ny)) return -1;
        if (!visited[nx][ny]) {
            visited[nx][ny] = true;
            cntFish += copied[nx][ny].size();
        }
        x = nx;
        y = ny;
    }

    return cntFish;
}

// 상어 이동 루트 결정 :: 백트래킹
void findRoute(int cnt) {
    if (cnt == 3) {
        int cntFish = simulation();
        if (cntFish > maxCnt) {
            for (int i = 0; i < 3; i++) {
                route[i] = tempRoute[i];
            }
            maxCnt = cntFish;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        tempRoute[cnt] = i;
        findRoute(cnt + 1);
    }

    return;
}

// 냄새 값 변경
void removeSmell() {
    for (int j = 1; j <= 4; j++) {
        for (int i = 1; i <= 4; i++) {
            if (smell[i][j] > 0) smell[i][j]--;
        }
    }

    return;
}

// 상어 이동하면서
// 먹을 물고기 있으면 clear 시켜주고
// 냄새 남기기 :: 2로
void moveShark() {
    int x = sx;
    int y = sy;
    for (int i = 0; i < 3; i++) {
        int dir = route[i];
        int nx = x + sdx[dir];
        int ny = y + sdy[dir];
        if (copied[nx][ny].size() != 0) {
            smell[nx][ny] = 2;
            copied[nx][ny].clear();
        }
        x = nx;
        y = ny;
    }
    sx = x;
    sy = y;

    return;
}

void finishMagic() {
    for (int j = 1; j <= 4; j++) {
        for (int i = 1; i <= 4; i++) {
            if (copied[i][j].empty()) continue;
            for (int k = 0; k < copied[i][j].size(); k++) {
                fish[i][j].push_back(copied[i][j].at(k));
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> S;
    for (int i = 0; i < M; i++) {
        cin >> fy >> fx >> d;
        fish[fx][fy].push_back(d);
    }
    cin >> sy >> sx;

    while (S--) {
        maxCnt = -1;
        copyFish();  // 물고기 복제
        findRoute(0);  // 상어 이동 루트 결정
        removeSmell();  // 기존 냄새 없애기
        moveShark();  // 상어 이동, 냄새 남기기
        finishMagic(); // 마법 종료
    }

    int res = 0;
    for (int j = 1; j <= 4; j++) {
        for (int i = 1; i <= 4; i++) {
            res += fish[i][j].size();
        }
    }

    cout << res;

    return 0;
}