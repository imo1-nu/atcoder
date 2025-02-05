#include <bits/stdc++.h>
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

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    auto l_lis = LIS(A);
    reverse(A.begin(), A.end());
    for (int &x : A) x *= -1;
    auto r_lis = LIS(A);
    reverse(r_lis.begin(), r_lis.end());

    int L = *max_element(l_lis.begin(), l_lis.end());
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        if (l_lis[i] + r_lis[i] - 1 == L) {
            ans.push_back(i + 1);
        }
    }

    int m = ans.size();
    cout << m << endl;
    for (int i = 0; i < m; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
