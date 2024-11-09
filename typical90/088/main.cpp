#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll N, Q;
ll A[88], X[4000], Y[4000];
vector<ll> G[88];
bool used[88];
bool counged[8889];

void dfs(ll u, ll sum) {
    if (u == N) {
        if (sum == 0) return;
        if (counged[sum] == false) {
            counged[sum] = true;
        }
        else {
            cout << "No" << endl;
            exit(0);
        }
    }

    if (used[u] == false) {
        sum += A[u];
        for (ll v : G[u]) {
            used[v] = true;
        }
        dfs(u + 1, sum);
        sum -= A[u];
        for (ll v : G[u]) {
            used[v] = false;
        }
    }

    dfs(u + 1, sum);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> Q;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (ll i = 0; i < Q; i++) {
        cin >> X[i] >> Y[i];
        X[i]--; Y[i]--;
        G[X[i]].push_back(Y[i]);
    }

}
