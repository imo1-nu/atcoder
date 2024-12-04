#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    

    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    int N = S.size();
    int m = 2019;
    vector<int> pow10(N);
    pow10[0] = 1;
    for (int i = 1; i < N; i++) {
        pow10[i] = pow10[i - 1] * 10 % m;
    }

    vector<int> cnt(m);
    cnt[0] = 1;
    int cur = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        cur += (S[i] - '0') * pow10[i];
        cur %= m;
        ans += cnt[cur]++;
    }

    cout << ans << endl;
}
