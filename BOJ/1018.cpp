// 230411
// BOJ 1018 체스판 다시 칠하기
// Brute Force

#include <iostream>
#define INF 987654321
#define MAX 51
using namespace std;

char board[MAX][MAX];
int n, m, max_x, max_y, cnt, min_cnt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cin >> board[i][j];
        }
    }

    max_x = n - 7;
    max_y = m - 7;
    min_cnt = INF;
    
    char start_color;
    for (int j = 0; j < max_y; j++) {
        for (int i = 0; i < max_x; i++) {
            start_color = board[i][j];
            cnt = 0;
            for (int y = j; y < j + 8; y++) {
                if (y % 2 == j % 2) {  // 같은 패턴
                    if (board[i][y] != start_color) cnt++;
                    if (board[i+2][y] != start_color) cnt++;
                    if (board[i+4][y] != start_color) cnt++;
                    if (board[i+6][y] != start_color) cnt++;

                    if (board[i+1][y] == start_color) cnt++;
                    if (board[i+3][y] == start_color) cnt++;
                    if (board[i+5][y] == start_color) cnt++;
                    if (board[i+7][y] == start_color) cnt++;
                }
                else {  // 반대 패턴
                    if (board[i][y] == start_color) cnt++;
                    if (board[i+2][y] == start_color) cnt++;
                    if (board[i+4][y] == start_color) cnt++;
                    if (board[i+6][y] == start_color) cnt++;

                    if (board[i+1][y] != start_color) cnt++;
                    if (board[i+3][y] != start_color) cnt++;
                    if (board[i+5][y] != start_color) cnt++;
                    if (board[i+7][y] != start_color) cnt++;
                }
            }
            cnt = min(cnt, 64 - cnt);
            min_cnt = min(min_cnt, cnt);
        }
    }

    cout << min_cnt;

    return 0;
}