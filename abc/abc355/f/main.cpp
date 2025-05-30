#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using dsu = atcoder::dsu;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<dsu> D(11, dsu(N));
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        for (int j = c; j <= 10; j++) {
            D[j].merge(a, b);
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += D[i].groups().size() - 1;
    }
    while (Q--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        for (int j = c; j <= 10; j++) {
            if (D[j].same(a, b)) continue;
            D[j].merge(a, b);
            ans--;
        }
        cout << ans << endl;
    }
}
