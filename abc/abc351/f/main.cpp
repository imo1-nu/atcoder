#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define INF 9223372036854775807

struct SegTree { //区間和を求める仕様
    vector<ll> tree;
    ll left = 1;
    ll ie = 0; //初期化(単位元)

    void init(ll size) {
        while (left < size) left *= 2;
        tree.resize(left * 2, ie); //初期化
    }

    ll get(ll index) {
        return tree[left + index];
    }

    ll parent(ll a, ll b) { //親の作り方
        return a + b;
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
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[A[i]] = 0;
    }
    int idx = 0;
    for (auto& p : mp) {
        p.second = idx++;
    }
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        B[i] = mp[A[i]];
    }

    SegTree seg1, seg2;
    seg1.init(N);
    seg2.init(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        seg1.update(B[i], seg1.get(B[i]) + A[i]);
        seg2.update(B[i], seg2.get(B[i]) + 1);
        ans += seg2.query(0, B[i]) * A[i] - seg1.query(0, B[i]);
    }
    cout << ans << endl;
}
