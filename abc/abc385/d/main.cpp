#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, M, x, y;
    cin >> N >> M >> x >> y;
    map<ll, set<ll>> X, Y;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        X[x].insert(y);
        Y[y].insert(x);
    }

    vector<pair<char, int>> P;
    for (int i = 0; i < M; ++i) {
        char c;
        int d;
        cin >> c >> d;
        P.emplace_back(c, d);
    }

    int ans = 0;
    for (auto [c, d] : P) {
        vector<pair<int, int>> v;
        if (c == 'U') {
            auto l = X[x].lower_bound(y);
            auto r = X[x].upper_bound(y + d);
            while (l != r) {
                v.emplace_back(x, *l);
                l++;
            }
            y += d;
        }
        if (c == 'D') {
            auto l = X[x].lower_bound(y - d);
            auto r = X[x].upper_bound(y);
            while (l != r) {
                v.emplace_back(x, *l);
                l++;
            }
            y -= d;
        }
        if (c == 'R') {
            auto l = Y[y].lower_bound(x);
            auto r = Y[y].upper_bound(x + d);
            while (l != r) {
                v.emplace_back(*l, y);
                l++;
            }
            x += d;
        }
        if (c == 'L') {
            auto l = Y[y].lower_bound(x - d);
            auto r = Y[y].upper_bound(x);
            while (l != r) {
                v.emplace_back(*l, y);
                l++;
            }
            x -= d;
        }
        for (auto [x, y] : v) {
            X[x].erase(y);
            Y[y].erase(x);
            ++ans;
        }
        // cout << x + 1 << " " << y + 1 << ' ' << ans << endl;
    }
    cout << x << " " << y << ' ' << ans << endl;
}
