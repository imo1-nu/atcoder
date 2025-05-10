#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int A, B;
    cin >> A >> B;
    int a = 0, b = 0;
    for (int i = 1; i <= 100; i *= 10) {
        a += A / i % 10;
        b += B / i % 10;
    }
    cout << max(a, b) << endl;
}
