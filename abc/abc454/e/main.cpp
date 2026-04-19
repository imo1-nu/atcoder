#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// LRUD
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<vector<vector<bool>>> dp(N, vector<vector<bool>>(N, vector<bool>(4, false)));
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
