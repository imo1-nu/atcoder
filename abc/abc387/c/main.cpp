#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll myPow(ll x, int n) {
    ll res = 1;
    for (int i = 0; i < n; ++i) {
        res *= x;
    }
    return res;
}

ll solve(ll r) {
    vector<int> digits;
    while (r) {
        digits.push_back(r % 10);
        r /= 10;
    }
    reverse(digits.begin(), digits.end());
    int n = digits.size();
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == n) {
            res++;
            break;
        }
        res += myPow(digits[0], n - i - 1) * min(digits[0], digits[i]);
        if (digits[i] >= digits[0]) break;
    }
    for (int i = 0; i < n; ++i) {
        int mx = (i ? 9 : digits[i] - 1);
        for (int j = 1; j <= mx; ++j) {
            res += myPow(j, n - i - 1);
        }
    }
    return res;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll L, R;
    cin >> L >> R;
    cout << (solve(R) - solve(L - 1)) << endl;
}
