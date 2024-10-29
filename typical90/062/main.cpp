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
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];
    vector<vector<int>> G(N);
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        A[i]--; B[i]--;
        G[A[i]].push_back(i);
        G[B[i]].push_back(i);
        if (A[i] == i || B[i] == i) {
            q.push(i);
        }
    }

    vector<bool> isBlack(N, true);
    stack<int> ans;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (!isBlack[v]) continue;

        ans.push(v);
        isBlack[v] = false;
        for (int e : G[v]) {
            q.push(e);
        }
    }

    if (ans.size() != N) {
        cout << -1 << endl;
    } else {
        while (!ans.empty()) {
            cout << ans.top() + 1 << endl;
            ans.pop();
        }
    }
}
