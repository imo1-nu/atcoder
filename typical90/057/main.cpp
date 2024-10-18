#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll mod = 998244353;

ll myPow(ll a, ll b) {
    if (b == 0) return 1ll;
    ll c = myPow(a, b / 2);
    if (b % 2 == 0) return c * c % mod;
    return c * c % mod * a % mod;
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> T(N);
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        cin >> T[i];
        for (int j = 0; j < T[i]; j++) {
            int a;
            cin >> a;
            A[i][a - 1] = 1;
        }
    }

    string s;
    cin >> s;
    vector<int> S(M);
    for (int i = 0; i < M; i++) {
        S[i] = s[i] - '0';
    }

    for (int i = 0; i < M; i++) {
        for (int j = i; j < N; j++) {
            if (A[j][i] == 1) {
                swap(A[i], A[j]);
                swap(T[i], T[j]);
                break;
            }
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[j][i] == 1) {
                for (int k = 0; k < M; k++) {
                    A[j][k] ^= A[i][k];
                }
            }
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int j;
        for (j = 0; j < N; j++) {
            if (A[i][j] == 1) break;
        }
        if (j == M) cnt++;
    }
    
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        if (S[i] != B[i]) {
            if (A[i][i] == 0) {
                cout << 0 << endl;
                return 0;
            }
            for (int j = 0; j < M; j++) {
                B[j] ^= A[i][j];
            }
        }
    }
    
    // cout << myPow(2, cnt) << endl;
}
