#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<bool> visited(100009);
stack<ll> ANS;

using Graph = vector<vector<ll>>;
void dfs(Graph &G, stack<ll> &st, ll start, ll goal) { //G, distを用意する
    if (start == goal) {
        ANS = st;
        return;
    }
    visited[start] = true;
    for (auto v : G[start]) {
        if (!visited[v]) {
            st.push(v);
            dfs(G, st, v, goal);
            st.pop();
        }
    }
    return;
}



int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;
    Graph G(n + 1);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    stack<ll> ans;
    ans.push(1ll);
    dfs(G, ans, 1ll, n);
    stack<ll> st;
    while (!ANS.empty()) {
        st.push(ANS.top());
        //cout << ANS.top() << endl;
        ANS.pop();
    }

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << endl;
}
