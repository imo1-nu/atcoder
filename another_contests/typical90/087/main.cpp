#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

#define INF LLONG_MAX / 2

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, P, K;
    cin >> N >> P >> K;
    vector<vector<ll>> A(N, vector<ll>(N));
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    ll L = 0, R = INF;
    ll l = 0, r = INF;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        vector<vector<ll>> dist(N, vector<ll>(N, INF));
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) {
                if (A[i][j] != -1) {
                    dist[i][j] = A[i][j];
                }
                else {
                    dist[i][j] = m;
                }
            }
        }

        for (ll k = 0; k < N; k++) {
            for (ll k2 = 0; k2 < N; k2++) {
                for (ll k3 = 0; k3 < N; k3++) {
                    dist[k2][k3] = min(dist[k2][k3], dist[k2][k] + dist[k][k3]);
                }
            }
        }

        ll cnt = 0;
        for (ll k = 0; k < N; k++) {
            for (ll k2 = k + 1; k2 < N; k2++) {
                if (dist[k][k2] <= P) {
                    cnt++;
                }
            }
        }

        if (cnt < K) {
            r = m;
        }
        else {
            l = m;
        }
    }

    R = r;
    

    l = 0, r = INF;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        vector<vector<ll>> dist(N, vector<ll>(N, INF));
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) {
                if (A[i][j] != -1) {
                    dist[i][j] = A[i][j];
                }
                else {
                    dist[i][j] = m;
                }
            }
        }

        for (ll k = 0; k < N; k++) {
            for (ll k2 = 0; k2 < N; k2++) {
                for (ll k3 = 0; k3 < N; k3++) {
                    dist[k2][k3] = min(dist[k2][k3], dist[k2][k] + dist[k][k3]);
                }
            }
        }

        ll cnt = 0;
        for (ll k = 0; k < N; k++) {
            for (ll k2 = k + 1; k2 < N; k2++) {
                if (dist[k][k2] <= P) {
                    cnt++;
                }
            }
        }

        if (cnt > K) {
            l = m;
        }
        else {
            r = m;
        }
    }

    L = l;

    if (R == INF && r != INF) {
        cout << "Infinity" << endl;
    }
    else {
        cout << R - L - 1 << endl;
    }
}
