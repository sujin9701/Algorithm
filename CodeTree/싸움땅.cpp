// 230407
// CodeTree 싸움땅
// Simulation

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 31
using namespace std;

struct Person {
    int x, y, power, d, gun;
};

vector<int> guns[21][21];
Person player[MAX];
int point[MAX] = {0, };
int N, M, K, x, y, d, s, g;

int rival;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};


bool checkRange(int x, int y) {
    if (x < 1 || x > N || y < 1 || y > N) return false;
    return true;
}

// map에 뜬 자리만 표시
void move(int p) {
    Person person = player[p];
    int nx = person.x + dx[person.d];
    int ny = person.y + dy[person.d];
    if (!checkRange(nx, ny)) {
        player[p].d = (player[p].d + 2) % 4;
        nx = person.x + dx[player[p].d];
        ny = person.y + dy[player[p].d];
    }

    player[p].x = nx;
    player[p].y = ny;

    return;
}

void changeGun(int x, int y, int idx) {
    sort(guns[x][y].begin(), guns[x][y].end());
    int cnt = guns[x][y].size();
    // 총 없으면 가지기
    if (player[idx].gun == 0) {
        player[idx].gun = guns[x][y].at(cnt-1);
        guns[x][y].pop_back();
        return;
    }
    // 있는 경우 교체할지 확인
    if (guns[x][y].at(cnt-1) > player[idx].gun) {
        swap(player[idx].gun, guns[x][y].at(cnt-1));
    }
    return;
}

// 이미 사람이 있는 자리인지
bool isExist(int idx, int x, int y) {
    for (int i = 1; i <= M; i++) {
        if (i == idx) continue;
        if (player[i].x == x && player[i].y == y) {
            rival = i;
            return true;
        }
    }
    return false;
}

// 자리 땅땅땅
void afterWin(int idx, int x, int y) {
    player[idx].x = x;
    player[idx].y = y;
    if (guns[x][y].size() > 0) changeGun(x, y, idx);

    return;
}

void loserMove(int idx, int x, int y) {
    int nx = x + dx[player[idx].d];
    int ny = y + dy[player[idx].d];
    while (true) {
        if (checkRange(nx, ny) && !isExist(idx, nx, ny)) break;
        player[idx].d = (player[idx].d + 1) % 4;
        nx = x + dx[player[idx].d];
        ny = y + dy[player[idx].d];
    }
    player[idx].x = nx;
    player[idx].y = ny;

    return;
}

void afterLose(int idx, int x, int y) {
    // 총 내려놓기
    guns[x][y].push_back(player[idx].gun);
    player[idx].gun = 0;
    // 한 번 더 이동
    loserMove(idx, x, y);
    // 총 있으면 센 총 갖기
    int nx = player[idx].x;
    int ny = player[idx].y;
    if (guns[nx][ny].size() > 0) {
        changeGun(nx, ny, idx);
    }

    return;
}

// p1: 새로운 애, p2: 원래 있던 애
void fight(int p1, int p2) {
    int x = player[p2].x;
    int y = player[p2].y;

    int power1 = player[p1].power + player[p1].gun;
    int power2 = player[p2].power + player[p2].gun;
    int score = abs(power1 - power2);

    int winner;
    // p1가 이김
    if (power1 > power2) winner = p1;
    else if (power1 == power2) {
        // p1가 이김
        if (player[p1].power > player[p2].power) winner = p1;
        // p2가 이김
        else winner = p2;
    }
    // p2가 이김
    else winner = p2;
    int loser;
    if (winner == p1) loser = p2;
    else loser = p1;

    afterLose(loser, x, y);
    afterWin(winner, x, y);

    point[winner] += score;

    return;
}

void play() {
    // 1번 플레이어부터 한 칸씩 이동하면서 (M까지)
    // - 새로운 위치에 플레이어가 없으면 총 교체
    // - 있으면 싸워야 함
    for (int i = 1; i <= M; i++) {
        move(i);
        int nx = player[i].x;
        int ny = player[i].y;
        if (isExist(i, nx, ny)) {
            fight(i, rival);
        }
        else {
            if (guns[nx][ny].size() > 0) changeGun(nx, ny, i);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            cin >> g;
            guns[i][j].push_back(g);
        }
    }
    for (int i = 1; i <= M; i++) {
        cin >> y >> x >> d >> s;
        player[i] = {x, y, s, d, 0};
    }

    for (int i = 0; i < K; i++) {
        play();
    }

    for (int i = 1; i <= M; i++) {
        cout << point[i] << " ";
    }

    return 0;
}