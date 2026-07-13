#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int X, Y, L, R, A, B;
    cin >> X >> Y >> L >> R >> A >> B;

    int ans = 0;
    for (int i = A; i < B; i++) {
        if (L <= i && i < R) ans += X;
        else ans += Y;
    }
    cout << ans << endl;
}
