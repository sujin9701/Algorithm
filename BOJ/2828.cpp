// 230411
// BOJ 2828 사과 담기 게임
// Backtracking

#include <iostream>
#define MAX 21
using namespace std;

int n, m, j, now, basket_pos = 1, dist = 0;

void find_and_move() {
    if (now >= basket_pos && now < basket_pos + m) return;
    else {
        // 바구니 위치보다 왼쪽에 떨어짐
        if (now < basket_pos) {
            int move = basket_pos - now;
            //cout << "move: " << move << "\n";
            dist += move;
            basket_pos -= move;
        }
        // 바구니 위치보다 오른쪽에 떨어짐
        else {
            int move = now - (basket_pos + m) + 1;
            //cout << "move: " << move << "\n";
            dist += move;
            basket_pos += move;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> j;
    for (int i = 0; i < j; i++) {
        cin >> now;
        find_and_move();
        //cout << "now: " << basket_pos << "\n";
    }

    cout << dist;

    return 0;
}