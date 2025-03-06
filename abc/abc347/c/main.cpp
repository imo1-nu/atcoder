#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, A, B;
    cin >> N >> A >> B;
    set<ll> S;
    for (int i = 0; i < N; i++) {
        ll d;
        cin >> d;
        d--;
        d %= (A + B);
        S.insert(d);
        S.insert(d + A + B);
    }
    bool ans = false;
    vector<ll> v;
    for (auto x : S) {
        v.push_back(x);
    }
    for (int i = 0; i < (int)v.size() - 1; i++) {
        if (v[i + 1] - v[i] > B) {
            ans = true;
            break;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
