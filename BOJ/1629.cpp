// 230411
// BOJ 1629 곱셈
// 수학

#include <iostream>
using namespace std;

int a, b, c;

long long f(int n) {
    if (n == 0) return 1;

    long long k = f(n/2) % c;

    if (n % 2 == 0) return k * k % c;
    else return (k * k) % c * a % c;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;
    
    cout << f(b);

    return 0;
}