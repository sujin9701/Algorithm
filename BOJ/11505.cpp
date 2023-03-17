// 230317
// BOJ 11505. 구간 곱 구하기
// Index Tree

#include <iostream>
#define MAX 1 << 21
#define MOD 1000000007
using namespace std;

long long tree[MAX];
int n, m, k, a, b, c, startIdx = 1;
long long temp;

void update(int a, int value) {
    int idx = a + startIdx - 1;
    tree[idx] = value;
    idx /= 2;
    while (true) {
        if (idx == 0) break;
        temp = tree[idx*2] * tree[idx*2 + 1];
        tree[idx] = temp % MOD;
        idx /= 2;
    }

    return;
}

long long calculate(int a, int b) {
    long long res = 1;
    int left = a + startIdx - 1;
    int right = b + startIdx - 1;
    while (true) {
        if (left > right) break;
        if (left == right) {
            temp = res * tree[left];
            res = temp % MOD;
            break;
        }
        else {
            if (left % 2 == 1) {
                temp = res * tree[left++];
                res = temp % MOD;
            }
            left /= 2;
            if (right % 2 == 0) {
                temp = res * tree[right--];
                res = temp % MOD;
            }
            right /= 2;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    // find start index
    while (true) {
        if (n <= startIdx) break;
        startIdx <<= 1;
    }
    
    // complete a tree
    for (int i = startIdx; i < startIdx + n; i++) {
        cin >> tree[i];
    }
    for (int i = startIdx + n; i < startIdx * 2; i++) {
        tree[i] = 1;
    }
    for (int i = startIdx - 1; i > 0; i--) {
        temp = tree[i*2] * tree[i*2 + 1];
        tree[i] = temp % MOD;
    }

    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {  // update
            update(b, c);
        }
        else {  // a == 2, calculate
            cout << calculate(b, c) << "\n";
        }
    }

    return 0;
}