#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<int>> ans(N);
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int a;
            cin >> a;
            ans[a - 1].push_back(i + 1);
        }
    }

    for (auto a : ans) {
        cout << a.size() << " ";
        for (auto x : a) cout << x << " ";
        cout << endl;
    }
}
