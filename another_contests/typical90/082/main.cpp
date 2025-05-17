#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;
ll MyPow10[19];

mint func(ll x) {
    mint X = x;
    mint Y = 2;
    return X * (X + 1) / Y;
}

mint calc(ll L, ll R, ll keta) {
    if (R < MyPow10[keta]) return 0;
    if (L >= MyPow10[keta + 1]) return 0;
    if (L < MyPow10[keta]) L = MyPow10[keta];
    if (R >= MyPow10[keta + 1]) R = MyPow10[keta + 1] - 1;
    return (func(R) - func(L - 1)) * (keta + 1);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll L, R;
    cin >> L >> R;

    MyPow10[0] = 1;
    for (int i = 1; i <= 18; i++) {
        MyPow10[i] = MyPow10[i - 1] * 10;
    }

    mint ans = 0;
    for (int i = 0; i < 18; i++) {
        ans += calc(L, R, i);
    }
    if (R == MyPow10[18]) {
        mint a = R;
        a *= 19;
        ans += a;
    }
    cout << ans.val() << endl;
}
