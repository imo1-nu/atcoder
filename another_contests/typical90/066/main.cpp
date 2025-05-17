#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        L[i]--; R[i]--;
    }

    double ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int cnt = 0, all = 0;
            for (int k = L[i]; k <= R[i]; k++) {
                for (int l = L[j]; l <= R[j]; l++) {
                    if (k > l) cnt++;
                    all++;
                }
            }
            ans += (double)cnt / all;
        }
    }

    cout << fixed << setprecision(15) << ans << endl;
}
