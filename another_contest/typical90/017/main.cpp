#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

struct Line {
    int L, R, width;
};

#define INF 9223372036854775807

struct SegTree { //区間の合計を求める仕様
    vector<ll> tree;
    ll left;
    ll ie = 0; //初期化(単位元)
    SegTree(vector<ll> a) : tree(){
        ll size = a.size();
        ll i;
        for (i = 0; (1ll << i) < size; i++) {}
        left = (1ll << i);
        tree.resize(left * 2, ie); //初期化
        for (ll j = 0; j < size; j++) {
            tree[left + j] = a[j];
        }
        setting(left);
    }

    ll get(ll index) {
        return tree[left + index];
    }

    ll parent(ll a, ll b) { //親の作り方
        return a + b;
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
    
    int N, M;
    cin >> N >> M;
    vector<Line> lines(M);
    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;
        L--; R--;

        int width1 = R - L;
        int width2 = N - R + L;

        if (width1 <= width2) {
            lines[i] = {L, R, width1};
        } else {
            lines[i] = {R, L, width2};
        }
    }
    sort(lines.begin(), lines.end(), [](const Line& a, const Line& b) {
        return a.width < b.width;
    });
    
    vector<ll> a(N);
    SegTree seg(a);
    for (auto& line : lines) {
        seg.update(line.L, seg.get(line.L) + 1);
        seg.update(line.R, seg.get(line.R) + 1);
    }

    ll ans = 0;
    for (auto& line : lines) {
        if (line.L < line.R) {
            ans += seg.query(line.L + 1, line.R);
        }
        else {
            ans += seg.query(line.L + 1, N) + seg.query(0, line.R);
        }
        seg.update(line.L, seg.get(line.L) - 1);
        seg.update(line.R, seg.get(line.R) - 1);
    }
    cout << ans << endl;
}
