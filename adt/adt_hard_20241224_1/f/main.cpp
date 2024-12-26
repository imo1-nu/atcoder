#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    vector<string> S(N);
    vector<vector<int>> unSolved(N);
    vector<int> score(N);
    int mx = 0;
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
        score[i] = i + 1;
        for (int j = 0; j < M; ++j) {
            if (S[i][j] == 'x') {
                unSolved[i].push_back(A[j]);
            }
            else {
                score[i] += A[j];
            }
        }
        sort(unSolved[i].rbegin(), unSolved[i].rend());
        mx = max(mx, score[i]);
    }

    for (int i = 0; i < N; ++i) {
        int ans = 0;
        while (score[i] < mx) {
            score[i] += unSolved[i][ans++];
        }
        cout << ans << endl;
    }
}
