#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

#define INF 9223372036854775807

struct SegTree { //区間の和を求める仕様
    vector<mint> tree;
    int left = 1;
    mint ie = 0; //初期化(単位元)

    void init(int size) {
        while (left < size) left *= 2;
        tree.resize(left * 2, ie); //初期化
    }

    mint get(int index) {
        return tree[left + index];
    }

    mint parent(mint a, mint b) { //親の作り方
        return a + b;
    }

    void update(int index, mint x) {
        index += left;
        tree[index] = x;
        while (index > 1) {
            index /= 2;
            tree[index] = parent(tree[2 * index], tree[2 * index + 1]); //親を管理
        }
    }

    mint query(int l, int r) { //[l, r)は求めたい半区間
        return query2(l, r, 0, left, 1);
    }

private:
    mint query2(int l, int r, int a, int b, int u) { //[l, r)は求めたい半区間，[a, b)はセルに対応する半区間、uは現在のセル番号

        //考えようとしている区間が、[a, b)に全く含まれないなら、mint_MAXを返して、操作に影響しないようにする
        if (r <= a || b <= l) return ie;

        //考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
        if (l <= a && b <= r) return tree[u];

        //どちらでもない場合、seg_tree[index]の2つの子ノードに対して再帰的に操作を行う。
        mint value_L = query2(l, r, a, (a + b) / 2, 2 * u);
        mint value_R = query2(l, r, (a + b) / 2, b, 2 * u + 1);
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
    for (int i = 0; i < N; i++) cin >> A[i];
    map<int, int> mp;
    for (int i = 0; i < N; i++) mp[A[i]] = 0;
    int n = 0;
    for (auto& p : mp) p.second = n++;
    for (int i = 0; i < N; i++) A[i] = mp[A[i]];

    SegTree dp;
    dp.init(n);
    mint ans = 0;
    vector<mint> pow2(N + 1);
    vector<mint> inv(N + 1);
    for (int i = 0; i <= N; i++) {
        pow2[i] = mint(2).pow(i);
        inv[i] = pow2[i].inv();
    }
    for (int i = 0; i < N; i++) {
        ans += dp.query(0, A[i] + 1) * pow2[i];
        dp.update(A[i], dp.get(A[i]) + inv[i + 1]);
    }
    cout << ans.val() << endl;
}
