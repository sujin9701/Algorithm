// 230414
// BOJ 3980 선발 명단
// Backtracking

#include <iostream>
using namespace std;

// 선수마다 0~100
// TC 여러 개
// 구) 능력치의 합이 최대가 되는 경우

int player[11][11];
bool pos[11];
int T, max_power = 0;


// 테스트 케이스마다 초기화해줄 것
void init() {
    max_power = 0;
    for (int i = 0; i < 11; i++) pos[i] = false;
    return;
}

void input_data() {
    for (int j = 0; j < 11; j++) {
        for (int i = 0; i < 11; i++) {
            cin >> player[i][j];
        }
    }
    return;
}

// 백트래킹, 파라미터: 포지션 정할 선수, 지금까지 힘
// 종료 조건
// - 모든 선수 배치했다면 max 업데이트 후 return
// - 이번 선수 배치할 곳이 없다면 return
// 이번 선수 가능한 포지션 찾아서 (0 아니어야 함)
// 해당자리 true 바꾸고
// 백트래킹
// 해당 자리 false로 돌려놓기
void dfs(int now, int power) {
    // 모든 선수를 배치했다면
    // max 업데이트 후 return
    if (now == 11) {
        max_power = max(max_power,power);
        return;
    }
    // 이 선수의 가능한 포지션 찾기
    for (int i = 0; i < 11; i++) {
        // 이미 차지되어있는 자리면 패스
        if (pos[i]) continue;
        // 이 선수 배치 가능한 포지션이면 드가자
        if (player[i][now] > 0) {
            pos[i] = true;
            dfs(now + 1, power + player[i][now]);
            pos[i] = false;
        }
    }
    // 이 선수 아무데도 넣을 수 없다면 빠꾸
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    // 선수 번호: j

    while (T--) {
        init();
        input_data();
        dfs(0, 0);
        cout << max_power << "\n";
    }

    return 0;
}