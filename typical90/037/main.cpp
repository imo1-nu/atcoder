#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

#define INF 9223372036854775807

struct SegTree { //区間の最大値を求める仕様
    vector<ll> tree;
    ll left = 1;
    ll ie = -INF; //初期化(単位元)

    void init(ll size) {
        while (left < size) left *= 2;
        tree.resize(left * 2, ie); //初期化
    }

    ll get(ll index) {
        return tree[left + index];
    }

    ll parent(ll a, ll b) { //親の作り方
        return max(a, b);
    }

    void update(ll index, ll x) {
        index += left;
        tree[index] = x;
        while (index > 1) {
            index /= 2;
            tree[index] = parent(tree[2 * index], tree[2 * index + 1]); //親を管理
        }
    }

    ll query(ll l, ll r) { //[l, r)は求めたい半区間
        return query2(l, r, 0, left, 1);
    }

private:
    ll query2(ll l, ll r, ll a, ll b, ll u) { //[l, r)は求めたい半区間，[a, b)はセルに対応する半区間、uは現在のセル番号

        //考えようとしている区間が、[a, b)に全く含まれないなら、ll_MAXを返して、操作に影響しないようにする
        if (r <= a || b <= l) return ie;

        //考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
        if (l <= a && b <= r) return tree[u];

        //どちらでもない場合、seg_tree[index]の2つの子ノードに対して再帰的に操作を行う。
        ll value_L = query2(l, r, a, (a + b) / 2, 2 * u);
        ll value_R = query2(l, r, (a + b) / 2, b, 2 * u + 1);
        return parent(value_L, value_R);
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll W, N;
    cin >> W >> N;
    vector<ll> L(N), R(N), V(N);
    for (ll i = 0; i < N; i++) {
        cin >> L[i] >> R[i] >> V[i];
    }
    SegTree dp[N + 1];
    for (ll i = 0; i <= N; i++) {
        dp[i].init(W + 1);
    }
    dp[0].update(0, 0);
    for (ll i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];
        for (ll j = 0; j <= W; j++) {
            ll l = max(0LL, j - R[i - 1]);
            ll r = max(0LL, j - L[i - 1] + 1);
            dp[i].update(j, max(dp[i].get(j), dp[i - 1].query(l, r) + V[i - 1]));
        }
    }
    if (dp[N].get(W) < 0) {
        cout << -1 << endl;
    } else {
        cout << dp[N].get(W) << endl;
    }
}
