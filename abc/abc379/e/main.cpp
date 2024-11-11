#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    string S;
    cin >> S;

    vector<ll> A(N + 1);
    for (ll i = 1; i <= N; ++i) {
        A[i] = (S[i - 1] - '0') * i + A[i - 1];
    }

    ll c = 0;
    stack<char> ans;
    for (ll i = N; i >= 1 || c > 0; --i) {
        ans.push((A[i] + c) % 10 + '0');
        c = (A[i] + c) / 10;
    }
    
    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
}
