// 230405
// BOJ 20056 마법사 상어와 파이어볼
// Simulation

#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

struct Fireball {
    int m, s, d;
};

vector<Fireball> space[MAX][MAX];
vector<Fireball> newSpace[MAX][MAX];
int N, M, K, x, y, m, s, d;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void init() {
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            newSpace[i][j].clear();
        }
    }
    return;
}

void debugging() {
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            if (newSpace[i][j].empty()) continue;
            cout << "in (" << i << ", " << j << ")\n";
            vector<Fireball> now = newSpace[i][j];
            for (int k = 0; k < now.size(); k++) {
                cout << now.at(k).m << " " << now.at(k).s << " " << now.at(k).d << "\n";
            }
        }
    }
    return;
}

void moveOne(int x, int y, Fireball now) {
    int nx = x, ny = y;
    int dir = now.d;
    for (int i = 0; i < now.s % N; i++) {
        nx += dx[dir];
        if (nx > N) nx = 1;
        else if (nx < 1) nx = N;
        ny += dy[dir];
        if (ny > N) ny = 1;
        else if (ny < 1) ny = N;
    }
    newSpace[nx][ny].push_back(now);
    
    return;
}

void moveAll() {
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            for (int k = 0; k < space[i][j].size(); k++) {
                Fireball now = space[i][j].at(k);
                moveOne(i, j, now);
            }
        }
    }

    return;
}

// 방향 모두 같으면 true, 하나라도 다르면 false
bool findDir(vector<Fireball> now) {
    for (int i = 1; i < now.size(); i++) {
        if (now.at(i - 1).d % 2 != now.at(i).d % 2) return false;
    }

    return true;
}

// 파이어볼 바꾸기
void sharkMagic(int x, int y) {
    vector<Fireball> now = newSpace[x][y];
    newSpace[x][y].clear();

    int tempM = 0, tempS = 0;
    for (int i = 0; i < now.size(); i++) {
        tempM += now.at(i).m;
        tempS += now.at(i).s;
    }
    int oneM = tempM / 5;
    if (oneM == 0) return;
    int oneS = tempS / now.size();
    int newDir;
    if (findDir(now)) newDir = 0;
    else newDir = 1;
    for (int i = 0;i < 4; i++) {
        newSpace[x][y].push_back({oneM, oneS, newDir});
        newDir += 2;
    }

    return;
}

void findAndMagic() {
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            if (newSpace[i][j].size() > 1) {
                sharkMagic(i, j);
            }
        }
    }
}

void copySpace() {
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            space[i][j] = newSpace[i][j];
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> y >> x >> m >> s >> d;
        space[x][y].push_back({m, s, d});
    }

    while (K--) {
        init();
        moveAll();
        findAndMagic();
        copySpace();
    }

    int res = 0;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            for (int k = 0; k < space[i][j].size(); k++) {
                res += space[i][j].at(k).m;
            }
        }
    }

    cout << res;

    return 0;
}