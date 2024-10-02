#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }

    vector<ll> sortedA = A;
    vector<ll> S(N + 1);
    for (int i = 0; i < N; ++i) {
        S[i + 1] = S[i] + sortedA[i];
    }

    for (int i = 0; i < N; i++) {
        if (N == M) {
            cout << 0 << ' ';
            continue;
        }

        ll left = 0;
        ll right = K - sum;
        if (A[i] + right < sortedA[N - M]) {
            cout << -1 << ' ';
            continue;
        }

        auto itr = upper_bound(sortedA.begin(), sortedA.end(), A[i]);
        ll idx = itr - sortedA.begin() - 1;
        
        right++;
        if (idx < N - M) {
            while (left + 1 < right) {
                ll mid = (left + right) / 2;
                ll nokori = K - sum - mid;
                ll border = A[i] + mid;
                int idx1 = upper_bound(sortedA.begin(), sortedA.end(), border) - sortedA.begin();
                ll hituyou = (idx1 - (N - M)) * (border + 1) - (S[idx1] - S[N - M]);
                if (hituyou <= nokori) {
                    right = mid;
                }
                else {
                    left = mid;
                }
            }
        }
        else {
            while (left + 1 < right) {
                ll mid = (left + right) / 2;
                ll nokori = K - sum - mid;
                ll border = A[i] + mid;
                int idx1 = upper_bound(sortedA.begin(), sortedA.end(), border) - sortedA.begin();
                ll hituyou = (idx1 - (N - M - 1)) * (border + 1) - (S[idx1] - S[N - M - 1]) - (mid + 1);
                if (hituyou <= nokori) {
                    right = mid;
                }
                else {
                    left = mid;
                }
            }
        }
        cout << left << ' ';
    }
    cout << endl;
}
