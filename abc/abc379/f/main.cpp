#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    vector<tuple<int, int, int>> query(Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        query[i] = {l, r, i};
    }
    sort(query.begin(), query.end());

    vector<int> st;
    vector<int> ans(Q);
    for (int i = N - 1; i >= 0; i--) {
        while (query.size() != 0 && get<0>(query.back()) == i) {
            int l, r, idx;
            tie(l, r, idx) = query.back();
            query.pop_back();
            ans[idx] = st.rend() - lower_bound(st.rbegin(), st.rend(), r + 1);
        }
        
        while (st.size() != 0 && H[st.back()] < H[i]) {
            st.pop_back();
        }
        st.push_back(i);
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }
}
