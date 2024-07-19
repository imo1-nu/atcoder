#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    ll max = sqrt(n);
    stack<ll> st;
    for (ll i = 1; i <= max; i++) {
        if (n % i == 0) {
            cout << i << endl;
            if (i * i != n)st.push(n / i);
        }
    }
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}
