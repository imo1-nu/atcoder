#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int op(int a, int b) { return max(a, b); }
int e() { return -1e9; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
    }
    vector<int> rate(500001);
    iota(rate.begin(), rate.end(), 0);
    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(rate);
    for (int i = 0; i < N; i++) {
        auto l = seg.max_right(0, [&](int x) { return x < L[i]; });
        auto r = seg.max_right(0, [&](int x) { return x <= R[i]; });
        seg.apply(l, r, 1);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int x;
        cin >> x;
        cout << seg.get(x) << endl;
    }
}
