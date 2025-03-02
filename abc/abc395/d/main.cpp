#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<set<int>> G(N);
    vector<int> num(N), num_inv(N), pos(N);
    for (int i = 0; i < N; i++) {
        G[i].insert(i);
        num[i] = i;
        num_inv[i] = i;
        pos[i] = i;
    }
    while (Q--) {
        int t, a, b;
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            a--, b--;
            G[pos[a]].erase(a);
            G[num_inv[b]].insert(a);
            pos[a] = num_inv[b];
        }
        else if (t == 2) {
            cin >> a >> b;
            a--, b--;
            swap(num_inv[a], num_inv[b]);
            swap(num[num_inv[a]], num[num_inv[b]]);
        }
        else {
            cin >> a;
            a--;
            cout << num[pos[a]] + 1 << endl;
        }
    }
}
