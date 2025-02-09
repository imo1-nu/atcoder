#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> P(N), Q(N), inv(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> Q[i];
        Q[i]--;
        inv[Q[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << Q[P[inv[i]]] + 1 << ' ';
    }
    cout << endl;
}
