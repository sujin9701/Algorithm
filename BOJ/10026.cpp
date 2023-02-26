// 230226
// BOJ 10026 적록색약

#include <iostream>
#define MAX 102
using namespace std;

char picture[MAX][MAX];
bool isVisited[MAX][MAX];
int n, res;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void init() {
    res = 0;
    for (int i = 0; i <= n + 1 ; i++) {
        for (int j = 0; j <= n + 1; j++) {
            isVisited[i][j] = false;
        }
    }
    return;
}

void dfs(int x, int y) {
    isVisited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // out of range
        if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
        if (!isVisited[nx][ny] && picture[x][y] == picture[nx][ny]) {
            dfs(nx, ny);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> picture[i][j];
        }
    }

    // normal
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!isVisited[i][j]) {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << " ";

    // change G to R
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n ; j++) {
            if (picture[i][j] == 'G') picture[i][j] = 'R';
        }
    }

    // red-green medicine
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!isVisited[i][j]) {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << "\n";

    return 0;
}