#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    string S;
    cin >> N >> Q >> S;

    vector<int> S1(N + 1), S2(N + 1);
    for (int i = 1; i <= N; i++) {
        S1[i] = S1[i - 1] + (S[i - 1] == '1');
        S2[i] = S2[i - 1] + (S[i - 1] == '2');
    }
    vector<int> idx;
    for (int i = 0; i < N; i++) {
        if (S[i] == '/') {
            idx.push_back(i);
        }
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        int lef = lower_bound(idx.begin(), idx.end(), l) - idx.begin();
        int rig = lower_bound(idx.begin(), idx.end(), r) - idx.begin();
        if (lef == rig) {
            cout << 0 << endl;
            continue;
        }
        rig--;

        int ans = 0;
        while (lef <= rig) {
            int m = (lef + rig) / 2;
            int p = idx[m];

            int l1 = S1[p] - S1[l];
            int r2 = S2[r] - S2[p];

            ans = max(ans, 2 * min(l1, r2) + 1);
            if (l1 >r2) rig = m - 1;
            else lef = m + 1;
        }
        cout << ans << endl;
    }
}