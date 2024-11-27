#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

bool solve2(ll X, ll Y, ll A, ll B) {
    for (int i = 0; i < 2; i++) {
        ll len = (A + X - 1) / X;
        if (len < Y && X * (Y - len) >= B) {
            return true;
        }
        swap(X, Y);
    }
    return false;
}

bool solve3(ll X, ll Y, ll A, ll B, ll C) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            ll len = (A + X - 1) / X;
            if (len < Y && solve2(X, Y - len, B, C)) {
                return true;
            }
            swap(A, B);
            swap(B, C);
        }
        swap(X, Y);
    }
    return false;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    bool ans = solve3(X, Y, A, B, C);
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
