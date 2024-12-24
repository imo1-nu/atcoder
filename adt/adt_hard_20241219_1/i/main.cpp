#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, M;
    int Q;
    cin >> N >> M >> Q;

    auto f = [](mint a, ll d, mint l) {
        return (2 * a + d * (l - 1)) * l / 2;
    };

    auto row = [&](int A, int C, int D) {
        if ((A + C) % 2 == 0) C++;
        if (C > D) return mint(0);
        ll a = A * M + C;
        int d = 2;
        int l = (D - C) / 2 + 1;
        return f(a, d, l);
    };

    while (Q--) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        --A, --B;

        mint first = row(A, C, D);
        mint second = row(A + 1, C, D);
        int cnt1 = (D - C) / 2 + 1;
        int cnt2 = (D - C + 1) / 2;
        if ((A + C) % 2 == 0) swap(cnt1, cnt2);

        if (A == B) {
            cout << first.val() << endl;
            continue;
        }

        mint ans = f(first, ll(2) * M * cnt1, (B - A) / 2 + 1) + f(second, ll(2) * M * cnt2, (B - A - 1) / 2 + 1);
        cout << ans.val() << endl;
    }
}
