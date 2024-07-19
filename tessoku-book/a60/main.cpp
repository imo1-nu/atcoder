#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[i] >= st.top().first) {
            st.pop();
        }
        if (st.empty()) cout << -1;
        else cout << st.top().second + 1;
        if (i == n - 1) cout << endl;
        else cout << ' ';
        st.push(make_pair(a[i], i));
    }
}