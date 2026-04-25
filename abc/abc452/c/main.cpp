#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    cin >> M;
    vector<string> S(M);
    for (auto& s : S) {
        cin >> s;
    }

    vector<vector<string>> size(11);
    vector<vector<vector<bool>>> check(11, vector<vector<bool>>(11, vector<bool>(26, false)));
    for (const auto&s : S) {
        size[s.length()].push_back(s);
        for (int i = 0; i < s.length(); i++) {
            check[s.length()][i][s[i] - 'a'] = true;
        }
    }
    for (const auto&s : S) {
        if (s.length() != N) {
            cout << "No" << endl;
            continue;
        }
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (!check[A[i]][B[i] - 1][s[i] - 'a']) ok = false;
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
}
