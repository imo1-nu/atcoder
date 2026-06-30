#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    ll A, B, X, Y;
    cin >> A >> B >> X >> Y;
    if (X < 0) X *= -1;
    if (Y < 0) Y *= -1;
    if (X > Y) {
        swap(A, B);
        swap(X, Y);
    }

    ll sum = 0;
    if (A <= B * 3 && A * 3 >= B) {
        if (A <= B) {
            sum = 2 * A * X;
            sum += (Y - X) / 2 * (A + B) + ((Y - X) % 2) * B;
        }
        else {
            sum = 2 * B * X;
            sum += (Y - X) / 2 * (A + B) + ((Y - X) % 2) * B;
        }
    }
    else {
        if (A <= B) {
            sum = 2 * A * X;
            sum += (Y - X) / 2 * 4 * A + 3 * ((Y - X) % 2) * A;
        }
        else {
            sum = 2 * B * X;
            sum += (Y - X) / 2 * 4 * B + ((Y - X) % 2) * B;
        }
    }
    cout << sum << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
