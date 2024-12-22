#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    S += S;
    ll ans = 1e18;
    for (int i = 0; i < N; i++) {
        string s = S.substr(i, N);
        ll cnt = i * A;
        for (int i = 0; i < N / 2; i++) {
            if (s[i] != s[N - i - 1]) cnt += B;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}
