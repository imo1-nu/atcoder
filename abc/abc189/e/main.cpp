#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<vector<ll>> mat_mal(vector<vector<ll>> &A, vector<vector<ll>> &B) {
    ll N = A.size();
    vector<vector<ll>> C(N, vector<ll>(N));
    for (ll i = 0; i < N; i++) {
        for (ll k = 0; k < N; k++) {
            for (ll j = 0; j < N; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

vector<ll> mat_vec_mal(vector<vector<ll>> &A, vector<ll> &B) {
    ll N = A.size();
    vector<ll> C(N);
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            C[i] += A[i][j] * B[j];
        }
    }
    return C;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<vector<ll>> P(N, vector<ll>(3));
    for (ll i = 0; i < N; i++) {
        cin >> P[i][0] >> P[i][1];
        P[i][2] = 1;
    }

    ll M;
    cin >> M;
    vector<ll> op(M), p(M);
    for (ll i = 0; i < M; i++) {
        cin >> op[i];
        if (op[i] == 3 || op[i] == 4) {
            cin >> p[i];
        }
    }

    vector<vector<vector<ll>>> S(M + 1, vector<vector<ll>>(3, vector<ll>(3)));
    for (ll i = 0; i < 3; i++) {
        S[0][i][i] = 1;
    }

    for (int i = 0; i < M; i++) {
        vector<vector<ll>> A(3, vector<ll>(3));
        if (op[i] == 1) {
            A[0][1] = 1;
            A[1][0] = -1;
            A[2][2] = 1;
        }
        if (op[i] == 2) {
            A[0][1] = -1;
            A[1][0] = 1;
            A[2][2] = 1;
        }
        if (op[i] == 3) {
            A[0][0] = -1;
            A[1][1] = 1;
            A[2][2] = 1;
            A[0][2] = 2 * p[i];
        }
        if (op[i] == 4) {
            A[0][0] = 1;
            A[1][1] = -1;
            A[2][2] = 1;
            A[1][2] = 2 * p[i];
        }
        S[i + 1] = mat_mal(A, S[i]);
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        ll A, B;
        cin >> A >> B;
        B--;
        vector<ll> ans = mat_vec_mal(S[A], P[B]);
        cout << ans[0] << " " << ans[1] << endl;
    }
}
