#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<vector<int>> G(N + 1, vector<int>{-1});
    for (int i = 0; i < N; i++) {
        G[A[i]].push_back(i);
    }
    for (int i = 0; i <= N; i++) {
        G[i].push_back(N);
    }

    auto f = [&](vector<int> v) {
        ll res = 0;
        for (int i = 1; i < (int)v.size(); i++) {
            ll c = v[i] - v[i - 1];
            res += c * (c - 1) / 2;
        }
        return res;
    };

    auto merge = [&](vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < (int)a.size() && j < (int)b.size()) {
            if (a[i] < b[j]) {
                res.push_back(a[i]);
                i++;
            }
            else if (a[i] > b[j]) {
                res.push_back(b[j]);
                j++;
            }
            else {
                res.push_back(a[i]);
                i++;
                j++;
            }
        }
        return res;
    };

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += f(G[i - 1]);
        ans -= f(merge(G[i], G[i - 1]));
    }
    cout << ans << endl;
}
