// 230401
// BOJ 18411 Exam
// Event!

#include <iostream>
#include <algorithm>
using namespace std;

int score[3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 3; i++) {
        cin >> score[i];
    }

    sort(score, score + 3);

    cout << score[1] + score[2];

    return 0;
}