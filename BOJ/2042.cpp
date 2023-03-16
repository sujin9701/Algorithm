// 230316
// BOJ 2042 구간합 구하기
// Index Tree

#include <iostream>
#define MAX 1 << 21  // 2,097,152 (N <= 1,000,000)
using namespace std;

long long tree[MAX];
int N, M, K, a, b, startIdx = 1;
long long c;

void update(int a, long long value) {
    int idx = a + startIdx - 1;
    long long gap = value - tree[idx];
    tree[idx] = value;
    idx /= 2;
    while (true) {
        if (idx == 0) break;
        tree[idx] += gap;
        idx /= 2;
    }

    return;
}

long long calculate(int a, int b) {
    long long sum = 0;
    int left = startIdx + a - 1;
    int right = startIdx + b - 1;
    while (true) {
        if (left > right) break;
        if (left % 2 == 1) {
            sum += tree[left++];
        }
        left /= 2;
        if (right % 2 == 0) {
            sum += tree[right--];
        }
        right /= 2;
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    
    // find start index
    while (true) {
        if (N <= startIdx) break;
        startIdx <<= 1;
    }

    // complete a tree
    for (int i = startIdx; i < startIdx + N; i++) {
        cin >> tree[i];
    }
    for (int i = startIdx - 1; i > 0; i--) {
        tree[i] = tree[i*2] + tree[i*2 + 1];
    }

    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {  // update
            update(b, c);
        }
        else {  // a == 2, calculate sum
            cout << calculate(b, c) << "\n";
        }
    }

    return 0;
}