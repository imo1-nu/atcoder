#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ll_MAX 9223372036854775807

struct SegTree {
    vector<ll> tree;
    ll left, right;
    SegTree(vector<ll> a) {
        ll size = a.size();
        ll i;
        for (i = 0; (1ll << i) < size; i++) {}
        vector<ll> tree((1ll << i + 1) + 1);
        left = (1ll << i);
        right = left + size;
        for (ll j = 0; j < size; j++) {
            tree[left + j] = a[j];
        }
        setting(left);
    }

    ll parent(ll a, ll b) { //親の作り方
        return min(a, b);
    }
    
    void setting(ll length) {
        if (length == 1) return;
        for (ll i = length; i < 2 * length; i += 2) {
            tree[i / 2] = parent(tree[i], tree[i + 1]); 
        }
        return setting(length / 2);
    }

    void update(ll index, ll x) {
        index += left;
        tree[index] = x;
        while (index > 1) {
            index /= 2;
            tree[index] = parent(tree[2 * index], tree[index + 1]); //最小値を管理
        }
    }

    ll query(ll l, ll r) {
        return query2(l, r, 0, right - left, 1);
    }

    ll all() {
        ll j = 2;
        for (ll i = 1; i < right; i++) {
            if (i == j) {
                cout << endl;
                j *= 2;
            }
            cout << tree[i] << ' ';
        }
        
    }

private:
    ll query2(ll l, ll r, ll a, ll b, ll u) { //[l, r)は求めたい半区間，[a, b)はセルに対応する半区間，uは現在のセル番号

        //考えようとしている区間が、[a,b)に全く含まれないなら、ll_MAXを返して、操作に影響しないようにする。
        if (a >= right || b <= left) return ll_MAX;

        //考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
        if (a <= left && b >= right) return tree[u];

        //どちらでもない場合、seg_tree[index]の2つの子ノードに対して再帰的に操作を行う。
        ll value_L = query2(l, r, left, (left + right) / 2, 2 * u);
        ll value_R = query2(l, r, (left + right) / 2, right, 2 * u + 1);
        return parent(value_L, value_R);
    }
};

ll main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<ll> a(64);
    SegTree T(a);
    
}
