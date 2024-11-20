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
    
    int W, N;
    cin >> W >> N;
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
    }
    atcoder::lazy_segtree <int, op, e, int, mapping, composition, id> seg(vector<int>(W + 1, 0));
    for (int i = 0; i < N; i++) {
        int l = L[i], r = R[i];
        int h = seg.prod(l, r + 1);
        cout << h + 1 << '\n';
        seg.apply(l, r + 1, h + 1);
    }
}