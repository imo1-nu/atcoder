#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    string S;
    cin >> N >> S;
    vector<ll> C(N);
    for (ll i = 0; i < N; i++) cin >> C[i];
    vector<pair<ll, ll>> A(N - 1);
    if (S[0] == '0') {
        A[0].first = 0;
        A[0].second = C[0];
    }
    else {
        A[0].first = C[0];
        A[0].second = 0;
    }

    for (ll i = 1; i < N; i++) {
        if (S[i] == '0' && i % 2 == 0 || S[i] == '1' && i % 2 == 1) A[0].first += C[i];
        if (S[i] == '1' && i % 2 == 0 || S[i] == '0' && i % 2 == 1) A[0].second += C[i];
    }

    //cout << A[0].first << ' ' << A[0].second << endl;

    ll ans = min(A[0].first, A[0].second);

    for (ll i = 1; i < N - 1; i++) {
        A[i].first = A[i - 1].second;
        A[i].second = A[i - 1].first;
        if (S[i] == '0') {
            A[i].first -= C[i];
            A[i].second += C[i];
        }
        else {
            A[i].first += C[i];
            A[i].second -= C[i];
        }
        
        ans = min(ans, min(A[i].first, A[i].second));
    }

    cout << ans << endl;
    for (ll i = 0; i < N - 1; i++) {
        //cout << i << ' ' << A[i].first << ' ' << A[i].second << endl;
        //cout << S[i] << endl;
    }
}
