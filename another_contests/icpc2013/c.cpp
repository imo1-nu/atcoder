#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve() {
    string S;
    cin >> S;

    vector<vector<int>> G = vector<vector<int>>(1, vector<int>());
    int N = 0;
    int par = -1;
    map<int, int> mp;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '[') {
            N++;
            G.push_back(vector<int>());
            par++;
            G[par].push_back(N);
        }
        else if (S[i] == ']') {
            par--;
        }
        else {
            int start = i;
            int end = start;
            while (S[end] != ']') end++;
            mp[N] = (stoi(S.substr(start, end - start)) + 1) / 2;
            i = end - 1;
        }
    }

    function<int(int)> dfs = [&](int u) {
        // cout << u << endl;
        if (mp.count(u)) return mp[u];
        vector<int> cnt;
        for (int v : G[u]) {
            cnt.push_back(dfs(v));
        }
        sort(cnt.begin(), cnt.end());
        int res = 0;
        for (int i = 0; i <= cnt.size() / 2; i++) res += cnt[i];
        return res;
    };
    cout << dfs(1) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    while (N--) {
        solve();
    }
}
