#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    atcoder::dsu d(N + 1);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        d.merge(l - 1, r);
    }
    if (d.same(0, N)) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
