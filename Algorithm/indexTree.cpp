// 230316
// Index Tree 기본 코드 (범위합 구하기 기준)

#include <iostream>
#define MAX 129
using namespace std;

int tree[MAX];
int n, a, b, startIdx = 1;

void update(int a, int value) {
    int idx = a + startIdx - 1;
    int gap = value - tree[idx];
    tree[idx] = value;
    idx /= 2;
    while (true) {
        if (idx == 0) break;
        tree[idx] += gap;
        idx /= 2;
    }

    return;
}

int calculate(int a, int b) {
    int sum = 0;
    int left = a + startIdx - 1;
    int right = b + startIdx - 1;
    while (true) {
        if (left > right) break;  // findMax라면 if (left >= right여야 한대)
        if (left % 2 == 1) {  // left가 right child라면
            sum += tree[left++];
        }
        left /= 2;
        if (right % 2 == 0) {  // right가 left child라면
            sum += tree[right--];
        }
        right /= 2;
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    // find start index
    while (true) {
        if (n <= startIdx) break;
        startIdx <<= 1;
    }

    // save to leaf nodes
    for (int i = startIdx; i < startIdx + n; i++) {
        cin >> tree[i];
    }

    // save to all nodes
    for (int i = startIdx - 1; i > 0; i--) {
        tree[i] = tree[i*2] + tree[i*2 + 1];
    }

    cin >> a >> b;
    update(a, b);
    cin >> a >> b;
    int res = calculate(a, b);

    cout << res;

    return 0;
}