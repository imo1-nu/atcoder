#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int op(int a, int b) { return min(a, b); }
int e() { return 1e9; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> v(N + 1);
    for (int i = 1; i <= N; ++i) {
        if (S[i - 1] == '(') v[i] = v[i - 1] + 1;
        else v[i] = v[i - 1] - 1;
    }
    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(v);
    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            if (S[l - 1] == '(' && S[r - 1] == ')') seg.apply(l, r, -2);
            if (S[l - 1] == ')' && S[r - 1] == '(') seg.apply(l, r, 2);
            swap(S[l - 1], S[r - 1]);
        }
        else {
            bool ok = false;
            if (seg.prod(l - 1, r + 1) == seg.get(l - 1) && seg.get(l - 1) == seg.get(r)) ok = true;
            if (ok) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
