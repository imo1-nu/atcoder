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
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    function<ll(vector<int>, vector<int>)> solve = [&](vector<int> v1, vector<int> v2) {
        int n1 = v1.size(), n2 = v2.size();
        if (n1 == 0 || n2 == 0) return 0ll;
        vector<int> v1e, v1o, v2e, v2o;
        for (int i = 0; i < n1; ++i) {
            if (v1[i] % 2 == 0) v1e.push_back(v1[i]);
            else v1o.push_back(v1[i]);
        }
        for (int i = 0; i < n2; ++i) {
            if (v2[i] % 2 == 0) v2e.push_back(v2[i]);
            else v2o.push_back(v2[i]);
        }

        ll sum1e = 0, sum1o = 0, sum2e = 0, sum2o = 0;
        for (int i = 0; i < (int)v1e.size(); ++i) sum1e += v1e[i];
        for (int i = 0; i < (int)v1o.size(); ++i) sum1o += v1o[i];
        for (int i = 0; i < (int)v2e.size(); ++i) sum2e += v2e[i];
        for (int i = 0; i < (int)v2o.size(); ++i) sum2o += v2o[i];

        vector<int> v1e2, v1o2, v2e2, v2o2;
        for (int i = 0; i < (int)v1e.size(); ++i) v1e2.push_back(v1e[i] / 2);
        for (int i = 0; i < (int)v1o.size(); ++i) v1o2.push_back(v1o[i] / 2);
        for (int i = 0; i < (int)v2e.size(); ++i) v2e2.push_back(v2e[i] / 2);
        for (int i = 0; i < (int)v2o.size(); ++i) v2o2.push_back(v2o[i] / 2 + 1);

        ll ee = solve(v1e2, v2e2);
        ll eo = (ll)v1e.size() * sum2o + (ll)v2o.size() * sum1e;
        ll oe = (ll)v1o.size() * sum2e + (ll)v2e.size() * sum1o;
        ll oo = solve(v1o2, v2o2);
        return ee + eo + oe + oo;
    };

    auto f = [&](int x) {
        while (x % 2 == 0) x /= 2;
        return x;
    };

    ll ans = solve(A, A);
    for (int i = 0; i < N; ++i) {
        ans += f(2 * A[i]);
    }
    cout << ans / 2 << endl;
}
