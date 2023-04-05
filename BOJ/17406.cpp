// 230405
// BOJ 17406 배열 돌리기 4
// Backtracking

#include <iostream>
#include <algorithm>
#define INF 987654321
#define MAX 51
using namespace std;

struct CalData {
    int x, y, s;
};

int ary[MAX][MAX];
int tempAry[MAX][MAX];
CalData info[7];
bool visited[7];
int N, M, K, x, y, s, minValue = INF;

int findMin() {
    int minV = INF, tempV;
    for (int j = 1; j <= M; j++) {
        tempV = 0;
        for (int i = 1; i <= N; i++) {
            tempV += ary[i][j];
        }
        minV = min(minV, tempV);
    }

    return minV;
}

void calculate(int x1, int y1, int x2, int y2) {
    int ox1 = x1;
    int oy1 = y1;
    int ox2 = x2;
    int oy2 = y2;
    while (true) {
        if (x1 >= x2) {
            if (x1 == x2) {
                tempAry[x1][y1] = ary[x1][y1];
            }
            break;
        }
        // 오른쪽으로
        for (int i = x1; i < x2; i++) {
            tempAry[i+1][y1] = ary[i][y1];
        }
        // 아래쪽으로
        for (int i = y1; i < y2; i++) {
            tempAry[x2][i+1] = ary[x2][i];
        }
        // 왼쪽으로
        for (int i = x1+1; i <= x2; i++) {
            tempAry[i-1][y2] = ary[i][y2];
        }
        // 위쪽으로
        for (int i = y1+1; i <= y2; i++) {
            tempAry[x1][i-1] = ary[x1][i];
        }
        x1++;
        y1++;
        x2--;
        y2--;
    }

    // 원본에 옮기기
    for (int j = oy1; j <= oy2; j++) {
        for (int i = ox1; i <= ox2; i++) {
            ary[i][j] = tempAry[i][j];
        }
    }

    return;
}

void returnOrigin(int x1, int y1, int x2, int y2) {
    int ox1 = x1;
    int oy1 = y1;
    int ox2 = x2;
    int oy2 = y2;
    while (true) {
        if (x1 >= x2) {
            if (x1 == x2) {
                tempAry[x1][y1] = ary[x1][y1];
            }
            break;
        }
        // 왼쪽으로
        for (int i = x1+1; i <= x2; i++) {
            tempAry[i-1][y1] = ary[i][y1];
        }
        // 아래쪽으로
        for (int i = y1; i < y2; i++) {
            tempAry[x1][i+1] = ary[x1][i];
        }
        // 오른쪽으로
        for (int i = x1; i < x2; i++) {
            tempAry[i+1][y2] = ary[i][y2];
        }
        // 위쪽으로
        for (int i = y1+1; i <= y2; i++) {
            tempAry[x2][i-1] = ary[x2][i];
        }
        x1++;
        y1++;
        x2--;
        y2--;
    }

    // 원본에 옮기기
    for (int j = oy1; j <= oy2; j++) {
        for (int i = ox1; i <= ox2; i++) {
            ary[i][j] = tempAry[i][j];
        }
    }

    return;
}

void backtracking(int cnt) {
    if (cnt == K) {
        int temp;
        temp = findMin();
        minValue = min(minValue, temp);
        return;
    }
    for (int i = 0; i < K; i++) {
        if (!visited[i]) {
            visited[i] = true;
            CalData now = info[i];
            int x1 = now.x - now.s;
            int y1 = now.y - now.s;
            int x2 = now.x + now.s;
            int y2 = now.y + now.s;
            calculate(x1, y1, x2, y2);
            backtracking(cnt+1);
            returnOrigin(x1, y1, x2, y2);
            visited[i] = false;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N >> K;
    for (int j = 1; j <= M; j++) {
        for (int i = 1; i <= N; i++) {
            cin >> ary[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> y >> x >> s;
        info[i] = {x, y, s};
    }

    backtracking(0);

    cout << minValue;

    return 0;
}