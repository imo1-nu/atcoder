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
    int Q;
    cin >> Q;

    ll N = S.size();
    vector<ll> K(Q);
    for (int i = 0; i < Q; i++) {
        cin >> K[i];
        K[i]--;
    }
    for (int i = 0; i < Q; i++) {
        char ans = S[K[i] % N];

        ll M = K[i] / N;
        if (__builtin_parityll(M)) {
            ans ^= 32;
        }
        cout << ans;
        if (i < Q - 1) cout << ' ';
    }
    cout << endl;
}
