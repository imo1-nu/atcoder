#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// https://github.com/imo1-nu/atcoder/tree/main/lib

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (auto& s : S) cin >> s;

    map<string, vector<string>> G;
    for (auto s : S) {
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 6; j++) {
                string ns = s;
                ns[i] = '*';
                ns[j] = '*';
                G[s].push_back(ns);
                G[ns].push_back(s);
            }
        }
    }

    ll ans = 0;
}
