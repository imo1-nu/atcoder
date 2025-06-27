#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, S;
    cin >> N >> S;
    vector<int> T(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
    }
    bool ok = true;
    for (int i = 1; i <= N; i++) {
        if (T[i] - T[i - 1] > S) {
            ok = false;
            break;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
