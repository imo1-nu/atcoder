#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    string S;
    cin >> N >> Q >> S;
    atcoder::fenwick_tree<int> fw(N + 1);
    for (int i = 1; i < N; i++) {
        if (S[i - 1] != S[i]) fw.add(i, 1);
    }
    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            int x = fw.sum(l - 1, l);
            if (x == 1) fw.add(l - 1, -1);
            else fw.add(l - 1, 1);
            int y = fw.sum(r, r + 1);
            if (y == 1) fw.add(r, -1);
            else fw.add(r, 1);
        }
        else {
            int sum = fw.sum(l, r);
            if (sum == r - l) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
