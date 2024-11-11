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
    vector<int> T(M), W(M), S(M);
    for (int i = 0; i < M; i++) {
        cin >> T[i] >> W[i] >> S[i];
    }

    set<int> st;
    for (int i = 0; i < N; i++) {
        st.insert(i);
    }

    vector<vector<int>> fukki(M);
    vector<ll> ans(N);
    for (int i = 0; i < M; i++) {
        for (int j : fukki[i]) {
            st.insert(j);
        }

        if (st.empty()) continue;

        int x = *st.begin();
        ans[x] += W[i];
        int idx = lower_bound(T.begin(), T.end(), T[i] + S[i]) - T.begin();
        if (idx < M) {
            fukki[idx].push_back(x);
        }
        st.erase(x);
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}
