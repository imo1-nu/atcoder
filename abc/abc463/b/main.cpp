#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    char X;
    cin >> N >> X;
    vector<string> S(N);
    for (auto& s : S) cin >> s;
    bool ans = false;
    for (auto s : S) {
        if (s[X - 'A'] == 'o') ans = true;
    }
    cout << (ans ? "Yes" : "No") << endl;
}
