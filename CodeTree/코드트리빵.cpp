// 230408
// CodeTree 코드트리 빵
// Simulation + bfs

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 16
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;

// 사람 배열, 편의점 배열
struct Pos {
    int x, y;
};

// 베이스캠프 찾을 때 queue에서 사용할 것
struct Data {
    int x, y, dist;
};

Pos people[31];
Pos conv[31];
bool is_arrived[31]; // 각 사람이 도착했는지 저장
bool visited[MAX][MAX]; // 베이스캠프 찾을 때 방문여부 체크
int save_dist[MAX][MAX];

int map[MAX][MAX];  // 0: 빈공간, 1: 베이스캠프, -1: 못지나감
int n, m, x, y, d;
int cur_t, next_x, next_y, base_x, base_y;
vector<pii> change_to_brick;

// 상, 좌, 우, 하
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

// OK
bool check_range(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n) return false;
    return true;
}

// OK
bool all_finished() {
    for (int i = 1; i <= m; i++) {
        if (!is_arrived[i]) return false;
    }
    return true;
}

// OK
// 초기값 -1 :: 시작점을 0으로 해줄 것임
void init_saved_dist() {
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            save_dist[i][j] = -1;
        }
    }
    return;
}

void bfs_for_find_next(int store_x, int store_y) {
    queue<Data> q;

    // 시작 위치 저장
    save_dist[store_x][store_y] = 0;
    q.push({store_x, store_y, 0});

    while (true) {
        // cout << "bfs_for_find_next\n";
        if (q.empty()) break;
        Data now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (!check_range(nx, ny)) continue;  // 범위 밖
            if (map[nx][ny] == -1) continue;  // 벽
            if (save_dist[nx][ny] > -1) continue;  // 이미 지나감

            save_dist[nx][ny] = now.dist + 1;
            q.push({nx, ny, now.dist + 1});
        }
    }

    return;
}

// 최단거리 찾기 위해 모든 칸에 대해 bfs 진행
// next_x, next_y 업데이트
void find_and_move(int idx) {
    // idx번 사람의 목적지
    int store_x = conv[idx].x;
    int store_y = conv[idx].y;

    // idx번 사람의 현재 위치
    int person_x = people[idx].x;
    int person_y = people[idx].y;

    // 편의점으로부터의 거리 (모든 칸에 대해) 구할 것임
    // 모든 칸에 대해 구할 필요는 없나?
    bfs_for_find_next(store_x, store_y);

    // cout << "check next for " << idx << "\n";
    // for (int j = 1; j <= n; j++) {
    //     for (int i = 1; i <= n; i++) {
    //         cout << save_dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    // 편의점으로부터 최단 거리에 해당하는 칸 고르기
    // 벽이거나 범위 밖이면 확인 XXX
    int min_dist = INF;
    for (int i = 0; i < 4; i++) {
        int nx = person_x + dx[i];
        int ny = person_y + dy[i];

        if (!check_range(nx, ny)) continue;
        if (map[nx][ny] == -1 || save_dist[nx][ny] == -1) continue;

        min_dist = min(min_dist, save_dist[nx][ny]);
    }

    // 우선순위로 확인, 제일 먼저 나오는 최단거리 방향 칸으로 업데이트
    // 찾는 순간 멈추기
    // 벽이거나 범위 밖이면 확인 XXX
    for (int i = 0; i < 4; i++) {
        int nx = person_x + dx[i];
        int ny = person_y + dy[i];

        if (!check_range(nx, ny)) continue;
        if (map[nx][ny] == -1) continue;

        if (min_dist == save_dist[nx][ny]) {
            people[idx].x = nx;
            people[idx].y = ny;
            return;
        }
    }

    return;
}

// 사람이 새로 이동할 위치 찾기
// OK
void move_shortest(int idx) {
    init_saved_dist();
    // 최단 거리를 찾아서
    find_and_move(idx);
}

// OK
void check_arrived(int idx) {
    // 만약 편의점에 도착했다면
    if (conv[idx].x == people[idx].x && conv[idx].y == people[idx].y) {
        // 그 사람 도착했다고 표시해주기 :: is_arrived[idx] true로
        is_arrived[idx] = true;
        // change_to_brick에 해당 편의점 좌표 push_back
        change_to_brick.push_back(pii(conv[idx].x, conv[idx].y));
    }
    return;
}

// OK
void init_visited() {
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            visited[i][j] = false;
        }
    }
    return;
}

// basecamp 찾을 때 쓰는 bfs
// OK
void bfs_for_find_base(int store_x, int store_y) {
    queue<Data> q;

    // min_dist보다 작은거 찾으면 업데이트 해줄거야
    // 업데이트할 목록: min_dist, base_x, base_y
    int min_dist = INF;
    base_x = n+1, base_y = n+1;

    // queue에 넣기 전에 방문여부 바꿔주기!!
    visited[store_x][store_y] = true;
    q.push({store_x, store_y, 0});

    while (true) {
        // cout << "bfs_for_find_base\n";
        if (q.empty()) break;
        Data now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (!check_range(nx, ny)) continue;
            if (map[nx][ny] == -1) continue;  // 벽
            if (visited[nx][ny]) continue;

            // 베이스캠프를 찾으면 업데이트할지 결정하자
            // 근데 여기서 더 들어가진 말기 :: 차피 dist 커지니까
            // 조건: 거리 짧아지거나, 같으면 y작거나, 또같으면 x작을때
            if (map[nx][ny] == 1) {
                if (min_dist > now.dist + 1) {
                    min_dist = now.dist + 1;
                    base_x = nx;
                    base_y = ny;
                }
                else if (min_dist == now.dist + 1) {
                    if (base_y > ny) {
                        base_x = nx;
                        base_y = ny;
                    }
                    else if (base_y == ny) {
                        if (base_x > nx) {
                            base_x = nx;
                            base_y = ny;
                        }
                    }
                }
                else continue;
            }
            // 빈 공간이면 bfs 더 해봐도??
            else {
                visited[nx][ny] = true;
                q.push({nx, ny, now.dist + 1});
            }
        }
    }

    return;
}

// OK
void move_to_basecamp(int idx) {
    // t초니까 t번째 사람을 베이스캠프로 옮기기
    // 베이스캠프 찾는법: bfs

    // 방문여부 초기화
    init_visited();

    int store_x = conv[idx].x;
    int store_y = conv[idx].y;

    // base_x, base_y 업데이트될 것
    bfs_for_find_base(store_x, store_y);

    //cout << idx << " find basecamp: " << base_x << ", " << base_y << "\n";

    // 사람 베이스캠프로 옮기고
    // change_to_brick에 해당 위치 추가하기
    people[idx].x = base_x;
    people[idx].y = base_y;

    //cout << "CHECK change: " << people[idx].x << ", " << people[idx].y << "\n";

    change_to_brick.push_back(pii(base_x, base_y));

    return;
}

void simulation() {
    cur_t = 0;
    while (true) {
        // cout << "\nsimulation\n";
        // 종료 조건: 모든 사람이 편의점에 도착
        if (all_finished()) break;
        cur_t++;

        // for debugging
        //cout << "CUR TIME: " << cur_t << "\n";

        // 격자 안의 사람들은 이동
        // 아직 편의점에 도착하지 않은 사람만!!!
        for (int i = 1; i <= min(cur_t - 1, m); i++) {
            if (is_arrived[i]) continue;
            move_shortest(i);
            check_arrived(i);
        }

        // change_to_brick의 모든 위치 벽으로 만들어주고
        // :: 이번에 도착한 편의점, 베이스캠프 위치 들어있음
        // vector 초기화
        for (int i = 0; i < change_to_brick.size(); i++) {
            pii now = change_to_brick.at(i);
            map[now.first][now.second] = -1;
        }
        change_to_brick.clear();

        // t분에 t번 사람 격자 안으로 옮기기 (t <= m일 때만)
        if (cur_t <= m) {
            move_to_basecamp(cur_t);
        }

        // cout << "check map status\n";
        // for (int j = 1; j <= n; j++) {
        //     for (int i = 1; i <= n; i++) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        // cout << "\ncheck people's position\n";
        // for (int i = 1; i <= m; i++) {
        //     cout << i << ": " << people[i].x << ", " << people[i].y << "\n";
        // }

        // cout << "finish==============\n";

        // for debugging
        // for (int i = 1; i <= m; i++) {
        //     if (is_arrived[i]) cout << "T ";
        //     else cout << "F ";
        // }
        // if (cur_t == 7) break;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> y >> x;
        conv[i] = {x, y};
        people[i] = {0, 0};
    }

    simulation();

    cout << cur_t;

    return 0;
}