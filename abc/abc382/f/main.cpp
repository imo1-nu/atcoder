#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int op(int a, int b) { return max(a, b); }
int e() { return 0; }
int mapping(int f, int x) { 
    if (f == -1) return x;
    else return f;
}
int composition(int f, int g) {
    if (f == -1) return g;
    else return f;
}
int id() { return -1; }

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, N;
    cin >> H >> W >> N;
    vector<tuple<int, int, int, int>> B(N);
    for (int i = 0; i < N; i++) {
        int r, c, l;
        cin >> r >> c >> l;
        r--; c--;
        B[i] = {r, c, l, i};
    }
    sort(B.rbegin(), B.rend());

    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(W);
    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        int r, c, l, j;
        tie(r, c, l, j) = B[i];
        int x = seg.prod(c, c + l);
        ans[j] = H - x;
        seg.apply(c, c + l, x + 1);
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}
