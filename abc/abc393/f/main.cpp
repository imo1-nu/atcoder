#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

const int INF = 2e9;

// 最長増加部分列の長さを求める
vector<int> LIS(const vector<int> &a) {
    int N = (int)a.size();
    vector<int> dp(N, INF);
    vector<int> ret(N);
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];
        ret[i] = it - dp.begin() + 1;
    }
    return ret;
}


struct SegTree { //区間の最大値を求める仕様
    vector<int> tree;
    int left = 1;
    int ie = 0; //初期化(単位元)

    void init(int size) {
        while (left < size) left *= 2;
        tree.resize(left * 2, ie); //初期化
    }

    int get(int index) {
        return tree[left + index];
    }

    int parent(int a, int b) { //親の作り方
        return max(a, b);
    }

    void update(int index, int x) {
        index += left;
        tree[index] = x;
        while (index > 1) {
            index /= 2;
            tree[index] = parent(tree[2 * index], tree[2 * index + 1]); //親を管理
        }
    }

    int query(int l, int r) { //[l, r)は求めたい半区間
        return query2(l, r, 0, left, 1);
    }

private:
    int query2(int l, int r, int a, int b, int u) { //[l, r)は求めたい半区間，[a, b)はセルに対応する半区間、uは現在のセル番号

        //考えようとしている区間が、[a, b)に全く含まれないなら、ll_MAXを返して、操作に影響しないようにする
        if (r <= a || b <= l) return ie;

        //考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
        if (l <= a && b <= r) return tree[u];

        //どちらでもない場合、seg_tree[index]の2つの子ノードに対して再帰的に操作を行う。
        int value_L = query2(l, r, a, (a + b) / 2, 2 * u);
        int value_R = query2(l, r, (a + b) / 2, b, 2 * u + 1);
        return parent(value_L, value_R);
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    auto lis = LIS(A);
    vector<tuple<int, int, int>> queries(Q + 1);
    for (int i = 0; i < Q; i++) {
        int x, r;
        cin >> r >> x;
        queries[i] = {x, r, i};
    }
    queries[Q] = {INF, 0, Q};
    sort(queries.begin(), queries.end());

    vector<vector<int>> newA(Q + 1);
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(queries.begin(), queries.end(), make_tuple(A[i], 0, 0));
        int idx = it - queries.begin();
        newA[idx].push_back(i);
    }

    SegTree seg;
    seg.init(N);
    vector<int> ans(Q);
    for (int i = 0; i < Q; i++) {
        auto [x, r, k] = queries[i];
        for (auto j : newA[i]) {
            seg.update(j, lis[j]);
        }
        ans[k] = seg.query(0, r);
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }
}
