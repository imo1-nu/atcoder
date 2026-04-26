#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S;
    cin >> N >> S;
    vector<int> SA(N + 1), SB(N + 1), SC(N + 1);
    for (int i = 0; i < N; i++) {
        SA[i + 1] = SA[i];
        SB[i + 1] = SB[i];
        SC[i + 1] = SC[i];
        if (S[i] == 'A') SA[i + 1]++;
        if (S[i] == 'B') SB[i + 1]++;
        if (S[i] == 'C') SC[i + 1]++;
    }
    map<pair<int, int>, int> mpAB, mpBC, mpCA, mpABC;
    for (int i = 0; i <= N; i++) {
        mpAB[{SA[i] - SB[i], 0}]++;
        mpBC[{SB[i] - SC[i], 0}]++;
        mpCA[{SC[i] - SA[i], 0}]++;
        mpABC[{SA[i] - SB[i], SB[i] - SC[i]}]++;
    }

    ll ab = 0, bc = 0, ca = 0, abc = 0;
    for (int i = 0; i <= N; i++) {
        ab += mpAB[{SA[i] - SB[i], 0}] - 1;
        bc += mpBC[{SB[i] - SC[i], 0}] - 1;
        ca += mpCA[{SC[i] - SA[i], 0}] - 1;
        abc += mpABC[{SA[i] - SB[i], SB[i] - SC[i]}] - 1;
    }
    ab /= 2;
    bc /= 2;
    ca /= 2;
    abc /= 2;
    ll ans = (ll)N * (N + 1) / 2 - ab - bc - ca + 2 * abc;
    cout << ans << endl;
}
