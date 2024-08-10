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
    vector<string> S(N);
    int M = 0;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        M = max(M, (int)S[i].size());
    }
    vector<stack<char>> st(M);
    for (int i = 0; i < N; i++) {
        int j = 0;
        for (j = 0; j < (int)S[i].size(); j++) {
            st[j].push(S[i][j]);
        }
        for (; j < M; j++) {
            if (!st[j].empty()) st[j].push('*');
        }
    }
    for (int i = 0; i < M; i++) {
        while (!st[i].empty()) {
            cout << st[i].top();
            st[i].pop();
        }
        cout << endl;
    }
}
