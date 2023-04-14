// 230415
// BOJ 16234 인구 이동
// 구현

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#define MAX 51
using namespace std;

typedef pair<int, int> pii;

// 인접한 두 나라의 인구 차이가 L~R사이면 국경 연다 -> 인구이동 시작
// 연합: 국경 열린 상태
// 연합 이루는 인구 수는 (연합의 인구 수) / (칸 개수)가 된다. 소수점 버림
// 연합 해체, 국경선 닫음
// 구) 인구 이동 며칠동안 발생하는지, 무조건 2000 이하임

// 새로운 곳에 저장해야 할까? 여기저기서 동시에 일어날 거야
// 0) 방문여부 초기화
// 1) 전체 돌면서 방문 아직 안 한 곳만 할 거야
// 왜냐면 이미 가능했다면 같이 열렸을 거거든
// 상하좌우 확인하면서 인구 차이 확인하고 열수있는데까지 열기 :: BFS
// 2) 인구이동
// - 이중for문 돌면서 열린 곳 개수 세고 (열면서 해야겠다 얘네는)
// - 더해주기
// - 방문여부 true인 곳들에 인구 수 업데이트 해주기
// - 방문여부 초기화??? 안됨 방문여부 숫자로 표현해주자(초기값 0)
// 인구이동 할 수 있다면 flag = true, flag가 false면 멈춰

pii saved[MAX * MAX];
int map[MAX][MAX];
int visited[MAX][MAX];
int N, L, R, type;
bool flag;  // 국경 열 수 있다면 true, 없으면 false

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool check_range(int x, int y) {
    if (x < 1 || x > N || y < 1 || y > N) return false;
    return true;
}

bool can_open(int x1, int y1, int x2, int y2) {
    int gap = abs(map[x1][y1] - map[x2][y2]);
    if (gap >= L && gap <= R) return true;
    return false;
}

void init() {
    flag = false;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            visited[i][j] = 0;
        }
    }
    return;
}

void bfs(int x, int y, int type) {
    int cnt = 1;  // 이번 덩어리 나라 수
    int total = map[x][y];  // 인구 수

    queue<pii> q;
    visited[x][y] = type;
    q.push(pii(x, y));

    while (true) {
        if (q.empty()) break;
        pii now = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            // 범위 밖이면 패스
            if (!check_range(nx, ny)) continue;
            if (visited[nx][ny] > 0) continue;
            // 국경 열 수 있다면
            // 몇 번째 덩어린지 visited에 저장하고
            // q에 넣고
            // 합이랑 몇 개인지도 저장해놓고 벡터에 또 저장해놓자
            if (can_open(now.first, now.second, nx, ny)) {
                flag = true;
                visited[nx][ny] = type;
                cnt++;
                total += map[nx][ny];
                q.push(pii(nx, ny));
            }
        }
    }
    saved[type] = pii(total, cnt);
    return;
}

void open_border() {
    type = 1;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            if (visited[i][j] > 0) continue;
            bfs(i, j, type);
            type++;
        }
    }

    return;
}

void move_people() {
    for (int t = 1; t < type; t++) {
        // 국경 안 열린 곳은 패스 (한개만 카운트되어있음)
        if (saved[t].second == 1) continue;
        int new_people = saved[t].first / saved[t].second;
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= N; i++) {
                if (visited[i][j] == t) map[i][j] = new_people;
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // input data
    cin >> N >> L >> R;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            cin >> map[i][j];
        }
    }
    
    int cnt_day = 0;
    while (true) {
        // 방문 여부 초기화
        init();
        // 국경 열기 :: true or false 정해질 것
        open_border();
        if (!flag) break;
        cnt_day++;
        move_people();
    }

    cout << cnt_day;

    return 0;
}