#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

#define INF 9223372036854775807

struct info {
    int max = 0;
    int max_count = 0;
    int second_max = 0;
    int second_max_count = 0;
};

struct SegTree { //区間の最大値を求める仕様
    vector<info> tree;
    int left = 1;
    info ie; //初期化(単位元)

    void init(int size) {
        while (left < size) left *= 2;
        tree.resize(left * 2, ie); //初期化
    }

    info get(int index) {
        return tree[left + index];
    }

    info parent(info a, info b) { //親の作り方
        map<int, int> mp;
        mp[a.max] += a.max_count;
        mp[a.second_max] += a.second_max_count;
        mp[b.max] += b.max_count;
        mp[b.second_max] += b.second_max_count;
        info res;
        auto it = mp.rbegin();
        res.max = it->first;
        res.max_count = it->second;
        it++;
        res.second_max = it->first;
        res.second_max_count = it->second;
        return res;
    }

    void update(int index, int x) {
        index += left;
        tree[index].max = x;
        tree[index].max_count = 1;
        while (index > 1) {
            index /= 2;
            tree[index] = parent(tree[2 * index], tree[2 * index + 1]); //親を管理
        }
    }

    info query(int l, int r) { //[l, r)は求めたい半区間
        return query2(l, r, 0, left, 1);
    }

private:
    info query2(int l, int r, int a, int b, int u) { //[l, r)は求めたい半区間，[a, b)はセルに対応する半区間、uは現在のセル番号

        //考えようとしている区間が、[a, b)に全く含まれないなら、ll_MAXを返して、操作に影響しないようにする
        if (r <= a || b <= l) return ie;

        //考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
        if (l <= a && b <= r) return tree[u];

        //どちらでもない場合、seg_tree[index]の2つの子ノードに対して再帰的に操作を行う。
        info value_L = query2(l, r, a, (a + b) / 2, 2 * u);
        info value_R = query2(l, r, (a + b) / 2, b, 2 * u + 1);
        return parent(value_L, value_R);
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    SegTree seg;
    seg.init(N);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        seg.update(i, a);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx, x;
            cin >> idx >> x;
            idx--;
            seg.update(idx, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            info ans = seg.query(l, r);
            cout << ans.second_max_count << '\n';
        }
    }
}
