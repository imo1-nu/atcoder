#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    int Q;
    cin >> S >> Q;

    auto g = [&](char c, ll add) {
        return char('A' + (c - 'A' + add) % 3);
    };

    function<char(ll, ll)> f = [&](ll t, ll k) {
        if (t == 0) return S[k];
        if (k == 0) return g(S[0], t);
        return g(f(t - 1, k / 2), k % 2 + 1);
    };

    while (Q--) {
        ll t, k;
        cin >> t >> k;
        cout << f(t, k - 1) << endl;
    }
}
