#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<vector<int>> state(n);
    for (int i = 0; i < n; i++) {
        state[a[i]].push_back(w[i]);
    }
    for (int i = 0; i < n; i++) {
        sort(state[i].begin(), state[i].end());
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int size = state[i].size();
        for (int j = 0; j < size - 1; j++) {
            ans += state[i][j];
        }
    }
    cout << ans << endl;
}
