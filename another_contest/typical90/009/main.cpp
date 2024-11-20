#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    double ans = 0;
    for (int i = 0; i < N; i++) {
        vector<double> t(2 * N);
        for (int j = 0; j < N; j++) {
            if (i == j) t[j] = 1e18;
            else t[j] = atan2(Y[j] - Y[i], X[j] - X[i]);
        }
        for (int j = 0; j < N; j++) {
            t[j + N] = t[j] + 2 * M_PI;
        }
        sort(t.begin(), t.end());
        int p = 0;
        for (int j = 0; j < N; j++) {
            while(t[p + 1] <= t[j] + M_PI) p++;
            ans = max(ans, t[p] - t[j]);
        }
    }
    cout << fixed << setprecision(10) << ans / M_PI * 180 << endl;
}
