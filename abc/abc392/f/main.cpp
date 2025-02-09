#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int op(int a, int b) {return a + b;}
int e() {return 0;}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    atcoder::segtree<int, op, e> seg(vector<int>(N, 1));
    vector<int> ans(N);
    for (int i = N - 1; i >= 0; i--) {
        int pos = seg.max_right(0, [&](int x) {return x < P[i];});
        ans[pos] = i + 1;
        seg.set(pos, 0);
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
