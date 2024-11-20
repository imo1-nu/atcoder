#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

bool used[1 << 18];
vector<int> G[1 << 18];
vector<int> H[1 << 18];
vector<int> I;
ll cnts = 0;

void dfs(int pos) {
    used[pos] = true;
    for (int i : G[pos]) {
        if (used[i] == false) dfs(i);
    }
    I.push_back(pos);
}

void dfs2(int pos) {
    used[pos] = true;
    cnts++;
    for (int i : H[pos]) {
        if (used[i] == false) dfs2(i);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        G[A[i]].push_back(B[i]);
        H[B[i]].push_back(A[i]);
    }

    for (int i = 0; i < N; i++) {
        if (used[i] == false) dfs(i);
    }
    
    ll ans = 0;
    reverse(I.begin(), I.end());
    for (int i = 0; i < N; i++) used[i] = false;
    for (int i : I) {
        if (used[i] == false) {
            cnts = 0;
            dfs2(i);
            ans += cnts * (cnts - 1ll) / 2ll;
        }
    }
    cout << ans << endl;
}
