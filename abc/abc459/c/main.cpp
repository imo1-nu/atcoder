#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;

    int removed = 1;
    vector<int> cnt(N);
    vector<set<int>> S(600001);
    for (int i = 0; i < N; i++) S[0].insert(i);
    while (Q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            x--;
            cnt[x]++;
            S[cnt[x]].insert(x);
            if ((int)S[removed].size() == N) removed++;
        }
        else {
            cout << S[x + removed - 1].size() << endl;
        }
    }
}
