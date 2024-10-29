#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

long long MyPow10[6] = {1, 10, 100, 1000, 10000, 100000};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, K;
    cin >> N >> K;

    ll cnt = 0ll;
    ll start, len;
    vector<ll> A;
    map<ll, ll> S;
    A.push_back(N);
    S[N] = 0;
    while (1) {
        ll N2 = A[cnt];
        for (ll i = 0ll; i < 5ll; i++) {
            N2 += (A[cnt] / MyPow10[i]) % 10ll;
        }
        N2 %= 100000ll;
        cnt++;
        A.push_back(N2);
        // N2がすでに出てきたら終了
        if (S.find(N2) != S.end()) {
            start = S[N2];
            len = cnt - S[N2];
            break;
        }
        S[N2] = cnt;
    }

    if (K < start) {
        cout << A[K] << endl;
    }
    else {
        cout << A[start + (K - start) % len] << endl;
    }
}
