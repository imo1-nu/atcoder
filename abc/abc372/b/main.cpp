#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;



int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll M;
    cin >> M;
    ll Pow3 = 1;
    vector<ll> A;
    for (ll i = 0; i < 20; i++) {
        ll cnt = M / Pow3 % 3ll;
        for (ll j = 0; j < cnt; j++) {
            A.push_back(i);
            M -= Pow3;
        }
        Pow3 *= 3ll;
    }
    cout << A.size() << endl;
    for (ll i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
