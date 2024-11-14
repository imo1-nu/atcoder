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
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> cnt(N + 1);
    for (int i = 0; i < M; i++) {
        cnt[A[i]]++;
    }

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        if (cnt[i] == 0) {
            ans = i;
            break;
        }
    }

    for (int i = M; i < N; i++) {
        cnt[A[i]]++;
        cnt[A[i-M]]--;
        if (cnt[A[i-M]] == 0) {
            ans = min(ans, A[i-M]);
        }
    }

    vector<vector<int>> pos(N + 1);
    for (int i = 0; i < N; i++) {
        pos[A[i]].push_back(i);
    }

    cout << ans << endl;
}
