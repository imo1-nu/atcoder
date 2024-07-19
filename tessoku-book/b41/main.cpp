#include <bits/stdc++.h>
using namespace std;
using ll = long long;

stack<pair<int, int>> st;

int func(int x, int y) {
    if (x == 1 && y == 1) return 0;
    st.push({x, y});
    if (x > y) return func(x - y, y);
    return func(x, y - x);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int X, Y, x = 1, y = 1;
    cin >> X >> Y;
    func(X, Y);
    int n = st.size();
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << st.top().first << ' ' << st.top().second << endl;
        st.pop();
    }
    
}
