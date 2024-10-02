#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int D, N;
    cin >> D >> N;
    vector<ll> T(D);
    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        l--;
        T[l]++;
        T[r]--;
    }
    
    vector<ll> S(D + 1);
    for (int i = 1; i <= D; i++) {
        S[i] = S[i - 1] + T[i - 1];
        cout << S[i] << endl;
    }
}
