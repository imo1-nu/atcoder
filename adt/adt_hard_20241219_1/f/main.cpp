#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S, T;
    cin >> S >> T;
    int N = S.size();
    queue<pair<int, char>> q;
    for (int i = 0; i < N; ++i) {
        if (S[i] > T[i]) q.push({i, T[i]});
    }
    for (int i = N - 1; i >= 0; --i) {
        if (S[i] < T[i]) q.push({i, T[i]});
    }

    cout << q.size() << endl;
    string X = S;
    while (!q.empty()) {
        auto [i, c] = q.front();
        q.pop();
        X[i] = c;
        cout << X << endl;
    }
}
