#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<bool> used(N + 1);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        used[a] = true;
    }

    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (!used[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int a : ans) {
        cout << a << ' ';
    }
    cout << endl;
}
