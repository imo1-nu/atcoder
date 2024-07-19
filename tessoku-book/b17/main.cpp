#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> h(n);
    vector<pair<int, int>> dp(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    dp[0].second = -1;
    dp[1] = {abs(h[1] - h[0]), 0};
    for (int i = 2; i < n; i++) {
        int min = i - 2;
        if (dp[i - 2].first + abs(h[i] - h[i - 2]) > dp[i - 1].first + abs(h[i] - h[i - 1])) min++;
        dp[i] = {dp[min].first + abs(h[i] - h[min]), min};
    }
    
    stack<int> st;
    for (int i = n - 1; i != -1; i = dp[i].second) {
        st.push(i + 1);
    }

    cout << st.size() << endl;
    while(st.size() > 1) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << st.top() << endl;
}
