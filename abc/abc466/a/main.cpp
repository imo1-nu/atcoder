#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    bool ok = true;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x >= 0) ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
}
