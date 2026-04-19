#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

string remove(string& S) {
    string removed;
    for (auto c : S) {
        removed += c;
        if (removed.length() < 4) continue;
        if (removed.substr(removed.length() - 4, 4) == "(xx)") {
            for (int i = 0; i < 4; i++) removed.pop_back();
            removed += "xx";
        }
    }
    return removed;
}

void solve() {
    string A, B;
    cin >> A >> B;
    A = remove(A);
    B = remove(B);
    cout << (A == B ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while(T--) solve();
}
