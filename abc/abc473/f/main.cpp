#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using S = int;
using F = int;
S op(S l,S r) {return min(l,r);}
S e() {return 1e9;}
S mapping(F l,S r) {return (l+r);}
F composition(F l,F r) {return (l+r);}
F id() {return 0;}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    string str;
    cin >> N >> str >> Q;
    vector<int> sum(N + 1);
    for (int i = 0; i < N; i++) {
        if (str[i] == 'A') sum[i + 1] = sum[i] + 1;
        else sum[i + 1] = sum[i] - 1;
    }

    atcoder::lazy_segtree<S,op,e,F,mapping,composition,id> seg(sum);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx;
            char c;
            cin >> idx >> c;
            idx--;
            int add = 0;
            if (str[idx] == 'A' && c == 'B') add = -2;
            if (str[idx] == 'B' && c == 'A') add = 2;
            str[idx] = c;
            seg.apply(idx + 1, N + 1, add);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            bool ok = (seg.prod(l, r + 1) == seg.get(l));
            cout << (ok ? "Yes" : "No") << endl;
        }
    }
}
