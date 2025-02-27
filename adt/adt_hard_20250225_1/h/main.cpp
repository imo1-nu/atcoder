#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> H(N + 1);
    H[0] = 1e9;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    vector<ll> ans(N + 1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i <= N; i++) {
        while (H[st.top()] < H[i]) {
            st.pop();
        }
        ans[i] = ans[st.top()] + ll(i - st.top()) * H[i];
        st.push(i);
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
}
