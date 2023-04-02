// 230402
// BOJ 27375 금공강 사수
// Backtracking

#include <iostream>
#define MAX 21

using namespace std;

struct Lesson {
    int w, s, e;
};

Lesson candi[MAX];
bool visited[MAX];
bool board[5][11] = {false, };
int N, K, w, s, e, sumCred, cnt = 0;

// 해당 수업 시간 비었는지
bool isEmpty(Lesson now) {
    int day = now.w;
    for (int k = now.s; k <= now.e; k++) {
        if (board[day][k]) return false;
    }

    return true;
}

// 학점 남아있는지
bool isAddable(Lesson now) {
    int nCred = now.e - now.s + 1;
    if (sumCred + nCred <= K) return true;
    return false;
}

void changeStatus(Lesson now, bool status) {
    int day = now.w;
    for (int k = now.s; k <= now.e; k++) {
        board[day][k] = status;
    }
    return;
}

void backtracking(int cred, int start) {
    if (cred == K) {  // 종료 조건
        cnt++;
        return;
    }

    // 재귀 해야함
    for (int i = start; i < N; i++) {
        if (!visited[i] && isEmpty(candi[i]) && isAddable(candi[i])) {

            // 시간표, 방문 여부 true로 바꿔주기
            visited[i] = true;
            changeStatus(candi[i], true);

            // 다음 수업 탐색
            int nCred = candi[i].e - candi[i].s + 1;
            backtracking(cred + nCred, i + 1);

            // true로 바꿨던거 다시 false로 바꿔주기
            visited[i] = false;
            changeStatus(candi[i], false);
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> w >> s >> e;
        candi[i] = {w, s, e};
        if (w == 5) visited[i] = true;  // 금요일 수업은 확인 안 할 거임
        else visited[i] = false;
    }

    backtracking(0, 0);
    cout << cnt;

    return 0;
}