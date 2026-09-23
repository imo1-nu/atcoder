#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S, T;
    cin >> N >> S >> T;
    bool ok = true;
    for (int i = 0; i < N; i++) {
        if (T[i] == '*') continue;
        if (S[i] != T[i]) ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
}
