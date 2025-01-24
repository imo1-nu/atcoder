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

    vector<vector<int>> V(4);
    for (int i = 0; i < N; i++) {
        if ((X[i] + Y[i]) % 2 == 0) {
            V[0].push_back(X[i] + Y[i]);
            V[1].push_back(- X[i] + Y[i]);
        }
        else {
            V[2].push_back(X[i] + Y[i]);
            V[3].push_back(- X[i] + Y[i]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        sort(V[i].begin(), V[i].end());
        int n = V[i].size();
        for (int j = 0; j < n; j++) {
            ans += ll(2 * j - (n - 1)) * V[i][j];
        }
    }
    cout << ans / 2 << endl;
}
