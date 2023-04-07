// 230407
// CodeTree 예술성
// Simulation

#include <iostream>
#include <queue>
#define MAX 40
using namespace std;

typedef pair<int, int> pii;

int pic[MAX][MAX];
int copied[MAX][MAX];
int groupCnt[MAX * MAX];
int gnum[MAX][MAX];
int n, totScore = 0, totalGrp;
queue<pii> q;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void init() {
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            gnum[i][j] = 0;
        }
    }
    return;
}

void initGroup() {
    for (int i = 1; i <= totalGrp; i++) {
        groupCnt[i] = 0;
    }
    return;
}

void initCopy() {
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            copied[i][j] = 0;
        }
    }
    return;
}

bool checkRange(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n) return false;
    return true;
}

void bfs(int x, int y, int s, int g) {
    int cnt = 1;
    gnum[x][y] = g;
    q.push(pii(x, y));
    while (true) {
        if (q.empty()) break;
        pii now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (!checkRange(nx, ny)) continue;
            if (gnum[nx][ny] > 0) continue;
            if (pic[nx][ny] != s) continue;
            cnt++;
            gnum[nx][ny] = g;
            q.push(pii(nx, ny));
        }
    }

    groupCnt[g] = cnt;

    return;
}

void findGroup() {
    init();
    int g = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (gnum[i][j] == 0) {
                bfs(i, j, pic[i][j], g++);
            }
        }
    }
    totalGrp = g - 1;

    return;
}

int calculate(int g1, int g2, int x1, int y1, int x2, int y2) {
    return (groupCnt[g1] + groupCnt[g2]) * pic[x1][y1] * pic[x2][y2];
}

int calScore() {
    // 그룹 정하고
    findGroup();
    // 예술점수 계산하기
    int score = 0;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (!checkRange(nx, ny)) continue;
                if (gnum[i][j] != gnum[nx][ny]) {
                    score += calculate(gnum[i][j], gnum[nx][ny], i, j, nx, ny);
                }
            }
        }
    }

    return score / 2;
}

void turnLeft(int a, int b, int c, int d) {
    int x1 = b, y1 = 1;
    int x2 = 1, y2 = b;
    int x3 = b, y3 = d;
    int x4 = d, y4 = b;

    while (y1 < b) {
        // 회전
        copied[x2][y2] = pic[x1][y1];
        copied[x3][y3] = pic[x2][y2];
        copied[x4][y4] = pic[x3][y3];
        copied[x1][y1] = pic[x4][y4];
        // 값 변경
        y1++; x2++; y3--; x4--;
    }

    copied[b][b] = pic[b][b];

    return;
}

void turnRightOnePart(int x, int y) {

    for (int j = 1; j <= n/2; j++) {
        for (int i = 1; i <= n/2; i++) {
            copied[n/2-j+1 + x][i + y] = pic[i + x][j + y];
        }
    }

    return;
}

void turnRight(int a, int b, int c, int d) {
    turnRightOnePart(0, 0);
    turnRightOnePart(b, 0);
    turnRightOnePart(0, b);
    turnRightOnePart(b, b);
    return;
}

void copyToOrigin() {
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            pic[i][j] = copied[i][j];
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> pic[i][j];
        }
    }

    // 예술점수 구하기
    totScore = calScore();

    int a = n / 2;
    int b = n / 2 + 1;
    int c = n / 2 + 2;
    int d = n;

    for (int i = 0; i < 3; i++) {
        initGroup();
        initCopy();
        turnLeft(a, b, c, d);
        turnRight(a, b, c, d);
        copyToOrigin();
        totScore += calScore();
    }

    cout << totScore;

    return 0;
}