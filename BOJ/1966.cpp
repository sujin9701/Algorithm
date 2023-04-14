// 230414
// BOJ 1966 프린터 큐

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

queue<pii> q;
int priority[10];
int T, N, x, a, find_n;

// x: 몇 번째로 인쇄되었는지 궁금한 문서가 현재 큐의 몇 번째에 위치하는가
// pair<초기 위치, 중요도>

void init() {
    find_n = 0;
    while (!q.empty()) q.pop();
    for (int i = 0; i < 10; i++) priority[i] = 0;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        init();
        cin >> N >> x;

        for (int i = 0; i < N; i++) {
            cin >> a;
            // 큐에 넣어주기
            q.push(pii(i, a));
            // 중요도 개수 추가
            priority[a]++;
        }

        int cnt = 0;
        while (true) {
            pii now = q.front();
            q.pop();
            // 얘보다 중요도 높은 문서 있으면 뒤에 넣고
            bool flag = true;
            for (int i = now.second + 1; i < 10; i++) {
                if (priority[i] > 0) {
                    flag = false;
                    break;
                }
            }
            if (!flag) q.push(now);
            // 아니면 뽑아주고 걔 중요도 하나 낮추기
            // 근데만약 그게나야? 프린트
            else {
                cnt++;
                if (now.first == x) {
                    cout << cnt << "\n";
                    break;
                }
                else {
                    priority[now.second]--;
                }
            }
        }
    }

    return 0;
}