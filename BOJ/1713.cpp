// 230414
// BOJ 1713 후보 추천하기
// 구현

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> pip;

// 처음: 다 비어있음
// 추천하는 순간 사진 게시되어야 함
// 빈칸없음:: 젤적은 추천수 학생 삭제, 새로 추천받은애 걸기
// - 두명이상 -> 제일 오랜된애 삭제
// 삭제되면 추천횟수 리셋됨

// 구) 최종 후보 누구?

vector<pip> v;
bool candi[MAX];  // 사진에 걸려있는지 저장
int N, K, x;  // x <= 1000, K <= 100

// 완탐 or 우큐  벡터..
// pair<<추천수,오래됨>, 학생번호>
// 이미 걸려있음 -> 걍추가  :: candi[MAX] = false / true
// 없음
// - 벡터크기 == N -> 정렬 후 맨앞의 애 쫓아내고 추가
// - 공간있으면 구냥추가

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> x;
        if (candi[x]) {
            // 찾아서 따봉수 추가
            for (int j = 0; j < v.size(); j++) {
                if (v[j].second == x) {
                    v[j].first.first++;
                    break;
                }
            }
        }
        else {
            // 공간있음
            if (v.size() < N) {
                candi[x] = true;
                v.push_back(pip(pii(1, i), x));
            }
            // 없음
            else {
                // 젤작은애 빼주기
                sort(v.begin(), v.end());
                pip now = v.front();
                candi[now.second] = false;
                v.erase(v.begin());
                // 새로운애 넣어주기
                v.push_back(pip(pii(1, i), x));
                candi[x] = true;
            }
        }
    }

    for (int i = 1; i <= 100; i++) {
        if (candi[i]) cout << i << " ";
    }

    return 0;
}