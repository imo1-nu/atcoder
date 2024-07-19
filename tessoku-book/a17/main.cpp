#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i < n; i++) {
        cin >> b[i];
    }
    vector<int> dp(n);
    vector<int> par(n, -1);
    stack<int> s;
    dp[1] = a[1];
    par[1] = 0;
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i -  1] + a[i], dp[i - 2] + b[i]);
        if (dp[i -  1] + a[i] < dp[i - 2] + b[i]) par[i] = i - 1;
        else par[i] = i - 2;
    }

    for (int p = n - 1; p != -1; p = par[p]) {
        s.push(p);
    }

    int size = s.size();
    cout << size << endl;
    for (int i = 0; i < size; i++) {
        cout << s.top() + 1;
        s.pop();
        if (i < size - 1) cout << ' ';
        else cout << endl;
    }
    
}
