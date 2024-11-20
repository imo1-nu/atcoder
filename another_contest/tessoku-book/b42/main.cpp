#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    
    //+ -
    vector<ll> score(4);
    ll A = 0, B = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] - b[i] > 0) {
            A += a[i];
            B += b[i];
        }
    }
    score[0] = A - B;

    //- +
    A = 0;
    B = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] - b[i] < 0) {
            A += a[i];
            B += b[i];
        }
    }
    score[1] = - A + B;

    //+ +
    A = 0;
    B = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] + b[i] > 0) {
            A += a[i];
            B += b[i];
        }
    }
    score[2] = A + B;

    //- -
    A = 0;
    B = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] + b[i] < 0) {
            A += a[i];
            B += b[i];
        }
    }
    score[3] = - A - B;

    ll ans = max_element(score.begin(), score.end()) - score.begin();
    cout << score[ans] << endl;
}
