#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Q;
    cin >> Q;
    stack<int> st;
    for (int i = 0; i < 100; i++) {
        st.push(0);
    }
    while (Q--) {
        int t, x;
        cin >> t;
        if (t == 1) {
            cin >> x;
            st.push(x);
        }
        else {
            cout << st.top() << '\n';
            st.pop();
        }
    }
}
