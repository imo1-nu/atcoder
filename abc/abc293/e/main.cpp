#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll mod;

vector<vector<ll>> mat_mul(vector<vector<ll>> a, vector<vector<ll>> b) {
    vector<vector<ll>> res(2, vector<ll>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

vector<vector<ll>> myPow(vector<vector<ll>> a, ll b) {
    vector<vector<ll>> res(2, vector<ll>(2));
    if (b == 0) {
        for (int i = 0; i < 2; i++) {
            res[i][i] = 1;
        }
        return res;
    }
    vector<vector<ll>> c = myPow(a, b / 2);
    res = mat_mul(c, c);
    if (b % 2 == 1) {
        res = mat_mul(res, a);
    }
    return res;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll A, X;
    cin >> A >> X >> mod;

    vector<vector<ll>> a = {{A, 1}, {0, 1}};
    vector<vector<ll>> res = myPow(a, X);
    cout << res[0][1] << endl;
}